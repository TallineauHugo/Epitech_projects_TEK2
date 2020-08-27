/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "proto.h"

static void set_null(serv_t *serv, int i, size_t size_tab)
{
	size_t y = 0;

	while (y <= size_tab) {
		serv->team_list[i].players[y] = NULL;
		y++;
	}
}

int init_max_p_team(serv_t *serv, int i)
{
	size_t size_tab = serv->nb_players_team;

	serv->team_list[i].players = malloc(
		sizeof(client_t *) * (size_tab + 1));
	if (serv->team_list[i].players == NULL)
		return 84;
	set_null(serv, i, size_tab);
	return 0;
}

char *return_s(short i)
{
	if (i == 0 || i == 1) {
		if (i == 0)
			return strdup("Team1");
		if (i == 1)
			return strdup("Team2");
	}
	if (i == 2)
		return strdup("Team3");
	if (i == 3)
		return strdup("Team4");
	return NULL;
}

int set_default_t(serv_t *serv)
{
	int i = 0;

	serv->team_list = malloc(sizeof(team_t) * (3 + 1));
	if (serv->team_list == NULL)
		return 84;
	memset(serv->team_list, 0, 4);
	serv->nb_t = 4;
	while (i < 4) {
		serv->team_list[i].name = return_s(i);
		if (serv->team_list[i].name == NULL)
			return 84;
		serv->team_list[i].nb_p = 0;
		if (init_max_p_team(serv, i) == 84)
			return 84;
		i++;
	}
	return 0;
}

int fill_teams_name(char **av, serv_t *serv)
{
	int i = 0;
	char **teams = name_teams(av);

	if (teams[0] == NULL)
		return set_default_t(serv);
	serv->team_list = malloc(sizeof(team_t) * (serv->nb_t + 1));
	if (serv->team_list == NULL)
		return 84;
	memset(serv->team_list, 0, serv->nb_t + 1);
	while (teams[i] != NULL) {
		serv->team_list[i].name = teams[i];
		serv->team_list[i].nb_p = 0;
		if (init_max_p_team(serv, i) == 84)
			return 84;
		i++;
	}
	return 0;
}

int calc_clients_max(info_t *info)
{
	size_t max_c = info->serv.nb_players_team * ((size_t)info->serv.nb_t);
	size_t i = 0;

	info->max_clients = max_c;
	info->clients = malloc(sizeof(client_t) * (max_c + 4));
	if (info->clients == NULL)
		return 84;
	while (i <= max_c + 4)
		info->clients[i++] = NULL;
	return 0;
}