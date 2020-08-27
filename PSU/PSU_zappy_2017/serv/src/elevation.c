/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <memory.h>
#include "struct.h"

void give_levels(p_manager_t *p_man)
{
	p_manager_t *tmp = p_man;

	while (tmp->next != NULL) {
		tmp->players->level++;
		tmp = tmp->next;
	}
	tmp->players->level++;
}

int one_two_three(map_t *map, client_t *client)
{
	int done = -1;
	int x = client->pos_x;
	int y = client->pos_y;

	if ((client->level == 1 && map->map[x][y].inventory->linemate) ||
		(client->level == 2 && map->map[x][y].nb_players > 1 &&
			map->map[x][y].inventory->linemate &&
			map->map[x][y].inventory->deraumere &&
			map->map[x][y].inventory->sibur) ||
		(client->level == 3 && map->map[x][y].nb_players > 1 &&
			map->map[x][y].inventory->linemate > 1 &&
			map->map[x][y].inventory->phiras > 1 &&
			map->map[x][y].inventory->sibur))
		done = 1;
	return done;
}

int four_five(map_t *map, client_t *client)
{
	int done = -1;
	int x = client->pos_x;
	int y = client->pos_y;

	if ((client->level == 4 && map->map[x][y].nb_players > 3 &&
		map->map[x][y].inventory->linemate &&
		map->map[x][y].inventory->phiras &&
		map->map[x][y].inventory->sibur > 1 &&
		map->map[x][y].inventory->deraumere) ||
		(client->level == 5 && map->map[x][y].nb_players > 3 &&
			map->map[x][y].inventory->linemate &&
			map->map[x][y].inventory->mendiane > 2 &&
			map->map[x][y].inventory->sibur &&
			map->map[x][y].inventory->deraumere > 1))
		done = 1;
	return done;
}

int six_seven(map_t *map, client_t *client)
{
	int done = -1;
	int x = client->pos_x;
	int y = client->pos_y;

	if ((client->level == 6 && map->map[x][y].nb_players > 5 &&
		map->map[x][y].inventory->linemate &&
		map->map[x][y].inventory->phiras &&
		map->map[x][y].inventory->sibur > 2 &&
		map->map[x][y].inventory->deraumere > 1) ||
		(map->map[x][y].nb_players > 5 &&
			map->map[x][y].inventory->linemate > 1 &&
			map->map[x][y].inventory->phiras > 1 &&
			map->map[x][y].inventory->sibur > 1 &&
			map->map[x][y].inventory->deraumere > 1 &&
			map->map[x][y].inventory->mendiane > 1 &&
			map->map[x][y].inventory->thystame))
		done = 1;
	return done;
}

void elevation(map_t *map, client_t *client)
{
	int first;
	int second;
	int third;

	first = one_two_three(map, client);
	second = four_five(map, client);
	third = six_seven(map, client);
	if (first == 1 || second == 1 || third == 1) {
		give_levels(map->map[client->pos_x][client->pos_y].players);
		write(client->fd, "ok\n", strlen("ok\n"));
	} else
		write(client->fd, "ko\n", strlen("ko\n"));
}