/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include <string.h>
#include "struct.h"

void set_food(map_t *map, client_t *client)
{
	if (client->inventory.food > 0) {
		map->map[client->pos_x][client->pos_y].inventory->food++;
		client->inventory.food--;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void set_linemate(map_t *map, client_t *client)
{
	if (client->inventory.linemate > 0) {
		map->map[client->pos_x][client->pos_y].inventory->linemate++;
		client->inventory.linemate--;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void set_deraumere(map_t *map, client_t *client)
{
	if (client->inventory.deraumere > 0) {
		map->map[client->pos_x][client->pos_y].inventory->deraumere++;
		client->inventory.deraumere--;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void set_sibur(map_t *map, client_t *client)
{
	if (client->inventory.sibur > 0) {
		map->map[client->pos_x][client->pos_y].inventory->sibur++;
		client->inventory.sibur--;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void set_mendiane(map_t *map, client_t *client)
{
	if (client->inventory.mendiane > 0) {
		map->map[client->pos_x][client->pos_y].inventory->mendiane++;
		client->inventory.mendiane--;
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}
