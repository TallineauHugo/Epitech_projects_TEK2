/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include <string.h>
#include "struct.h"

void set_phiras(map_t *map, client_t *client)
{
	if (client->inventory.phiras > 0) {
		map->map[client->pos_x][client->pos_y].inventory->phiras++;
		client->inventory.phiras--;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void set_thystame(map_t *map, client_t *client)
{
	if (client->inventory.thystame > 0) {
		map->map[client->pos_x][client->pos_y].inventory->thystame++;
		client->inventory.thystame--;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}
