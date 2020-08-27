/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

void take_phiras(map_t *map, client_t *client)
{
	if (map->map[client->pos_x][client->pos_y].inventory->phiras > 0) {
		map->map[client->pos_x][client->pos_y].inventory->phiras--;
		client->inventory.phiras++;
		map->map[rand() % map->x][rand() % map->y].inventory->phiras++;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void take_thystame(map_t *map, client_t *client)
{
	if (map->map[client->pos_x][client->pos_y].inventory->thystame > 0) {
		map->map[client->pos_x][client->pos_y].inventory->thystame--;
		client->inventory.thystame++;
		map->map[rand() % map->x][rand() %
			map->y].inventory->thystame++;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}
