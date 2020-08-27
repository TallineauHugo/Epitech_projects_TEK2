/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

void take_food(map_t *map, client_t *client)
{
	if (map->map[client->pos_x][client->pos_y].inventory->food > 0) {
		map->map[client->pos_x][client->pos_y].inventory->food--;
		client->inventory.food++;
		map->map[rand() % map->x][rand() % map->y].inventory->food++;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else {
		write(client->fd, "ko\n", strlen("ko\n"));
	}
}

void take_linemate(map_t *map, client_t *client)
{
	if (map->map[client->pos_x][client->pos_y].inventory->linemate > 0) {
		map->map[client->pos_x][client->pos_y].inventory->linemate--;
		client->inventory.linemate++;
		map->map[rand() % map->x][rand() %
			map->y].inventory->linemate++;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void take_deraumere(map_t *map, client_t *client)
{
	if (map->map[client->pos_x][client->pos_y].inventory->deraumere > 0) {
		map->map[client->pos_x][client->pos_y].inventory->deraumere--;
		client->inventory.deraumere++;
		map->map[rand() % map->x][rand() %
			map->y].inventory->deraumere++;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void take_sibur(map_t *map, client_t *client)
{
	if (map->map[client->pos_x][client->pos_y].inventory->sibur > 0) {
		map->map[client->pos_x][client->pos_y].inventory->sibur--;
		client->inventory.sibur++;
		map->map[rand() % map->x][rand() % map->y].inventory->sibur++;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void take_mendiane(map_t *map, client_t *client)
{
	if (map->map[client->pos_x][client->pos_y].inventory->mendiane > 0) {
		map->map[client->pos_x][client->pos_y].inventory->mendiane--;
		client->inventory.mendiane++;
		map->map[rand() % map->x][rand() %
			map->y].inventory->mendiane++;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}
