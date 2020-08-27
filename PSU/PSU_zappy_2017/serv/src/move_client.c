/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "broadcast.h"
#include "proto.h"

void move_client(client_t *client, map_t *map)
{
	if (client->dir == 0) {
		if (client->pos_x == 0)
			client->pos_x = (map->x - 1);
		else
			client->pos_x--;
	}
	if (client->dir == 1) {
		if (client->pos_y == 0)
			client->pos_y = (map->y - 1);
		else
			client->pos_y--;
	}
	if (client->dir == 2) {
		if ((size_t)client->pos_x == (map->x - 1))
			client->pos_x = 0;
		else
			client->pos_x++;
	}
}

void forward_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)arg;
	(void)info;
	remove_player_list(&map->map[client->pos_x][client->pos_y].players,
		client);
	map->map[client->pos_x][client->pos_y].nb_players--;
	move_client(client, map);
	if (client->dir == 3) {
		if ((size_t)client->pos_y == (map->y - 1))
			client->pos_y = 0;
		else
			client->pos_y++;
	}
	if (map->map[client->pos_x][client->pos_y].players == NULL)
		map->map[client->pos_x][client->pos_y].players =
			init_player_manager();
	add_player_list(&map->map[client->pos_x][client->pos_y].players,
		client);
	map->map[client->pos_x][client->pos_y].nb_players++;
	write(client->fd, "ok\n", strlen("ok\n"));
}

void right_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)map;
	(void)arg;
	(void)info;
	if (client->dir == 0)
		client->dir = 3;
	else
		client->dir--;
	write(client->fd, "ok\n", strlen("ok\n"));
}

void left_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)info;
	(void)arg;
	if (map) {
	}
	client->dir++;
	if (client->dir > 3)
		client->dir = 0;
	write(client->fd, "ok\n", strlen("ok\n"));
}