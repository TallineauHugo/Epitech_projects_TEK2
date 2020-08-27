/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/main
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "server.h"
#include "proto.h"

static int rp(int fd, team_t *team)
{
	client_t *tmp = NULL;
	size_t nb_p = 0;

	while (team->players[nb_p]->fd != fd)
		nb_p++;
	while (nb_p < team->nb_p - 1) {
		team->players[nb_p] = team->players[nb_p + 1];
		nb_p++;
	}
	team->players[nb_p] = tmp;
	team->nb_p--;
	return 0;
}

static int slot_team(int fd, info_t *info)
{
	int i = 0;
	size_t nb_p = 0;

	while (i < info->serv.nb_t) {
		while (info->serv.team_list[i].players[nb_p] != NULL) {
			if (fd != info->serv.team_list[i].players[nb_p]->fd) {
				nb_p++;
				continue;
			}
			return rp(
				info->serv.team_list[i].players[nb_p]->fd,
				&info->serv.team_list[i]);
		}
		i++;
		nb_p = 0;
	}
	return 0;
}

void client_write(int fd, char *buf)
{
	write(fd, buf, strlen(buf));
}

char *get_param(char *str)
{
	char *res;
	int i = -1;

	res = malloc(sizeof(char) * strlen(str));
	while (str[++i] != '\0') {
		if (str[i] == ' ')
			break;
	}
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	strcat(res, str + i);
	return res;
}

/*
** Fonction de clean d'un client, qui l'enlève bien de toutes les ressources (team, partie)
** Et qui free les variables qui dépendent de ce joueur
*/

void close_client(info_t *info, int fd)
{
	int posX;
	int posY;

	printf("Client [%d]: Connection closed\n", fd);
	close(fd);
	info->serv.fd_type[fd] = FD_FREE;
	info->serv.fct_read[fd] = NULL;
	info->serv.fct_write[fd] = NULL;
	posX = info->clients[fd]->pos_x;
	posY = info->clients[fd]->pos_y;
	if (info->clients[fd]->team == true)
		slot_team(fd, info);
	if (posX != -1 && posY != -1)
		info->serv.map->map[posX][posY].nb_players--;
	if (info->clients[fd]->teamName != NULL)
		free(info->clients[fd]->teamName);
	free(info->clients[fd]);
	info->nb_client--;
}
