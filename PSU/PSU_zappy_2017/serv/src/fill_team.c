/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "proto.h"

int tools_find_t1(size_t nbp, info_t *info, client_t *client, int i)
{
	if (nbp == info->serv.nb_players_team) {
		dprintf(client->fd, "ko (team Full)\n");
		return 84;
	}
	info->serv.team_list[i].players[nbp] = client;
	info->serv.team_list[i].nb_p++;
	return 0;
}

void tools_find_t2(size_t c, info_t *info, client_t *client)
{
	size_t posX;
	size_t posY;

	posX = rand() % info->serv.map->x;
	posY = rand() % info->serv.map->y;
	client->pos_x = posX;
	client->pos_y = posY;
	client->dir = (enum dir)(rand() % 4);
	info->serv.map->map[posX][posY].nb_players++;
	if (info->serv.map->map[client->pos_x][client->pos_y].players == NULL)
		info->serv.map->map[posX][posY].players = init_player_manager();
	add_player_list(&info->serv.map->map[posX][posY].players, client);
	dprintf(client->fd, "%ld\n", c);
	dprintf(client->fd, "%ld %ld\n", info->serv.map->x, info->serv.map->y);
}

int not_a_team(client_t *client)
{
	dprintf(client->fd, "ko (no such team)\n");
	return 84;
}

int find_my_team(info_t *info, client_t *client, char *buff)
{
	int i = 0;
	size_t nbp = 0;
	size_t c = 0;

	for (; i < info->serv.nb_t; i++) {
		if (strcmp(info->serv.team_list[i].name, buff) == 0) {
			nbp = info->serv.team_list[i].nb_p;
			if (tools_find_t1(nbp, info, client, i) == 84)
				return 84;
			c = info->serv.nb_players_team -
				info->serv.team_list[i].nb_p;
			tools_find_t2(c, info, client);
			break;
		}
	}
	if (i == info->serv.nb_t)
		return not_a_team(client);
	client->team = true;
	return 0;
}
