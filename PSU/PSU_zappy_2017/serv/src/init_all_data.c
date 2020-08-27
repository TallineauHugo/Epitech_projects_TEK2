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

/*
** Fonction d'appel à l'initialisation de la map
*/

int init_map(char **av, info_t *info)
{
	int x = get_width_map(av);
	int y = get_height_map(av);

	if (x == -1 || y == -1)
		return 84;
	info->serv.map = init_struct_map(info, get_width_map(av),
		get_height_map(av));
	return 0;
}

int fill_data_serv(char **av, info_t *info)
{
	info->serv.nb_players_team = get_clients_nb(av);
	info->serv.nb_t = nb_teams(av);
	if (info->serv.nb_t == -1 || (int)info->serv.nb_players_team == -1 ||
		fill_teams_name(av, &info->serv) == 84) {
		return -1;
	}
	info->serv.freq = get_freq(av);
	if (info->serv.nb_players_team <= 0 || info->serv.freq <= 0)
		return -1;
	if (calc_clients_max(info) == 84 || init_map(av, info) == 84)
		return -1;
	return 0;
}

int init_data(char **av, info_t *info)
{
	if (fill_data_serv(av, info) == -1) {
		if (info->serv.nb_t == -1) {
			return err_t(av);
		}
		return -1;
	}
	return 0;
}
