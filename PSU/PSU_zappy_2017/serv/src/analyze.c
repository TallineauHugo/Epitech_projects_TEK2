/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "vision.h"

char *analyse_verti(map_t *map, calc_t tool, char *msg, bool sens)
{
	for (int i = 0; i < tool.dec; i++) {
		while (tool.x >= (int)map->x)
			tool.x -= (int)map->x;
		while (tool.x < 0)
			tool.x += (int)map->x;
		for (int z = 0; z < map->map[tool.x][tool.y].nb_players; z++)
			msg = my_realloc(msg, " player");
		msg = get_loot(map->map[tool.x][tool.y].inventory, msg);
		sens == true ? tool.x++ : tool.x--;
		msg = my_realloc(msg, ",");
	}
	return msg;
}

char *analyse_hori(map_t *map, calc_t tool, char *msg, bool sens)
{
	for (int i = 0; i < tool.dec; i++) {
		while (tool.y >= (int)map->y)
			tool.y -= (int)map->y;
		while (tool.y < 0)
			tool.y += (int)map->y;
		for (int z = 0; z < map->map[tool.x][tool.y].nb_players; z++)
			msg = my_realloc(msg, " player");
		msg = get_loot(map->map[tool.x][tool.y].inventory, msg);
		sens == true ? tool.y++ : tool.y--;
		msg = my_realloc(msg, ",");
	}
	return msg;
}