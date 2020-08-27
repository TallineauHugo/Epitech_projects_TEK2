/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "struct.h"

static bag_t need_to_generate(info_t *info, uint32_t x, uint32_t y)
{
	bag_t bag;

	bag.food = (x * y);
	bag.thystame = THYSTAME_NEED * DENSITY * (int)info->max_clients;
	bag.phiras = PHIRAS_NEED * DENSITY * (int)info->max_clients;
	bag.linemate = LINEMATE_NEED * DENSITY * (int)info->max_clients;
	bag.mendiane = MENDIANE_NEED * DENSITY * (int)info->max_clients;
	bag.deraumere = DERAUMERE_NEED * DENSITY * (int)info->max_clients;
	bag.sibur = SIBUR_NEED * DENSITY * (int)info->max_clients;
	return bag;
}

static bag_t *xinit_bag(map_t *map, int i, int k)
{
	bag_t *bag = malloc(sizeof(bag_t));

	bag->food = 0;
	bag->linemate = 0;
	bag->deraumere = 0;
	bag->sibur = 0;
	bag->mendiane = 0;
	bag->phiras = 0;
	bag->thystame = 0;
	map->map[i][k].inventory = bag;
	return bag;
}

static void generate_loot(map_t *map, bag_t inventory)
{
	int i = 0;

	for (i = 0; i < inventory.food; i++)
		map->map[rand() % map->x][rand() % map->y].inventory->food++;
	for (i = 0; i < inventory.linemate; i++)
		map->map[rand() % map->x][rand() %
			map->y].inventory->linemate++;
	for (i = 0; i < inventory.deraumere; i++)
		map->map[rand() % map->x][rand() %
			map->y].inventory->deraumere++;
	for (i = 0; i < inventory.sibur; i++)
		map->map[rand() % map->x][rand() % map->y].inventory->sibur++;
	for (i = 0; i < inventory.mendiane; i++)
		map->map[rand() % map->x][rand() %
			map->y].inventory->mendiane++;
	for (i = 0; i < inventory.phiras; i++)
		map->map[rand() % map->x][rand() % map->y].inventory->phiras++;
	for (i = 0; i < inventory.thystame; i++)
		map->map[rand() % map->x][rand() %
			map->y].inventory->thystame++;
}

map_t *init_struct_map(info_t *info, uint32_t x, uint32_t y)
{
	map_t *map = malloc(sizeof(map_t));
	bag_t need = need_to_generate(info, x, y);

	if (map == NULL)
		return (NULL);
	map->x = x;
	map->y = y;
	map->map = calloc(sizeof(cell_t *) * (x + 1), sizeof(cell_t *));
	for (unsigned int i = 0; i < x; i++) {
		map->map[i] = calloc(sizeof(cell_t) * (y + 1), sizeof(cell_t));
		for (unsigned int k = 0; k < y; k++)
			map->map[i][k].inventory = xinit_bag(map, i, k);
	}
	generate_loot(map, need);
	return (map);
}

void free_map(map_t *map)
{
	for (unsigned int x = 0; x < map->x; x++) {
		for (unsigned int y = 0; y < map->y; y++) {
			free(map->map[x][y].inventory);
		}
		free(map->map[x]);
	}
	free(map->map);
	free(map);
}
