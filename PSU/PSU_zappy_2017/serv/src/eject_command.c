/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "broadcast.h"
#include "proto.h"

void erase_infos(cell_t cellFrom, cell_t cellTo, info_t *info, client_t *client)
{
	for (size_t i = 2; i < info->max_clients; i++) {
		if (info->clients[i]->pos_x == client->pos_x &&
			info->clients[i]->pos_y == client->pos_y) {
			if (!cellTo.players)
				cellTo.players = init_player_manager();
			add_player_list(&cellTo.players, info->clients[i]);
			remove_player_list(&cellFrom.players, info->clients[i]);
			cellTo.nb_players++;
			cellFrom.nb_players--;
		}
	}
}

void eject_client(client_t *client, info_t *info, map_t *map)
{
	int x;
	int y;

	if (client->dir == 0) {
		x = (int)client->pos_x - 1;
		if (x < 0)
			x = map->x - 1;
	}
	erase_infos(map->map[client->pos_x][client->pos_y],
		map->map[x][client->pos_y], info, client);
	if (client->dir == 1) {
		y = (int)client->pos_y - 1;
		if (y < 0)
			y = map->y - 1;
		erase_infos(map->map[client->pos_x][client->pos_y],
			map->map[client->pos_x][y], info, client);
	}
}

void eject_client_bis(client_t *client, info_t *info, map_t *map)
{
	int x;
	int y;

	if (client->dir == 2) {
		x = (int)client->pos_x + 1;
		if (x == client->pos_x - 1)
			x = 0;
		erase_infos(map->map[client->pos_x][client->pos_y],
			map->map[x][client->pos_y], info, client);
	}
	if (client->dir == 3) {
		y = (int)client->pos_y + 1;
		if (y == client->pos_y - 1)
			y = 0;
		erase_infos(map->map[client->pos_x][client->pos_y],
			map->map[client->pos_x][y], info, client);
	}
}

void eject_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)map;
	(void)arg;
	(void)info;

	if (!map->map[client->pos_x][client->pos_y].nb_players)
		write(client->fd, "ko\n", strlen("ko\n"));
	else {
		eject_client(client, info, map);
		eject_client_bis(client, info, map);
	}
}