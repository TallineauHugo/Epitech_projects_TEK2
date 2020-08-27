/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <memory.h>
#include "vision.h"

static char *look_up(map_t *map, client_t *player, char *msg)
{
	calc_t tool;

	tool.dec = 0;
	tool.x = player->pos_x;
	tool.y = player->pos_y;
	for (int i = 0; i <= player->level; i++) {
		msg = analyse_hori(map, tool, msg, true);
		tool.dec = (i + 1) * 2 + 1;
		tool.y--;
		if (--tool.x < 0)
			tool.x = (int)map->x - 1;
	}
	msg[strlen(msg) - 1] = '\0';
	msg = my_realloc(msg, "]");
	return msg;
}

static char *look_left(map_t *map, client_t *player, char *msg)
{
	calc_t tool;

	tool.dec = 0;
	tool.x = player->pos_x;
	tool.y = player->pos_y;
	for (int i = 0; i <= player->level; i++) {
		msg = analyse_verti(map, tool, msg, false);
		tool.dec = (i + 1) * 2 + 1;
		tool.x++;
		if (--tool.y < 0)
			tool.y = (int)map->y - 1;
	}
	msg[strlen(msg) - 1] = '\0';
	msg = my_realloc(msg, "]");

	return msg;
}

static char *look_right(map_t *map, client_t *player, char *msg)
{
	calc_t tool;

	tool.dec = 0;
	tool.x = player->pos_x;
	tool.y = player->pos_y;
	for (int i = 0; i <= player->level; i++) {
		msg = analyse_verti(map, tool, msg, true);
		tool.dec = (i + 1) * 2 + 1;
		tool.x--;
		if (++tool.y >= (int)map->y)
			tool.y = 0;
	}
	msg[strlen(msg) - 1] = '\0';
	msg = my_realloc(msg, "]");
	return msg;
}

static char *look_down(map_t *map, client_t *player, char *msg)
{
	calc_t tool;

	tool.dec = 0;
	tool.x = player->pos_x;
	tool.y = player->pos_y;
	for (int i = 0; i <= player->level; i++) {
		msg = analyse_hori(map, tool, msg, false);
		tool.dec = (i + 1) * 2 + 1;
		tool.y++;
		if (++tool.x >= (int)map->y)
			tool.x = 0;
	}
	msg[strlen(msg) - 1] = '\0';
	msg = my_realloc(msg, "]");
	return msg;
}

char *look(map_t *map, client_t *player)
{
	char *msg = strdup("[player");

	msg = get_loot(map->map[player->pos_x][player->pos_y].inventory, msg);
	msg = my_realloc(msg, ",");
	if (player->dir == UP)
		return look_up(map, player, msg);
	else if (player->dir == LEFT)
		return look_left(map, player, msg);
	else if (player->dir == RIGHT)
		return look_right(map, player, msg);
	else if (player->dir == DOWN)
		return look_down(map, player, msg);
	return NULL;
}
