/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/broadcast
*/

#include <stdlib.h>
#include "broadcast.h"

static const dirvariation_t g_variation[] = {{0 - M_PI_8, 0 + M_PI_8, S_EAST},
	{M_PI_4 - M_PI_8, M_PI_4 + M_PI_8, S_NORTH_EAST},
	{M_PI_2 - M_PI_8, M_PI_2 + M_PI_8, S_NORTH},
	{M_PI_4 * 3 - M_PI_8, M_PI_4 * 3 + M_PI_8, S_NORTH_WEST},
	{-M_PI_4 * 3 - M_PI_8, -M_PI_4 * 3 + M_PI_8, S_SOUTH_WEST},
	{-M_PI_2 - M_PI_8, -M_PI_2 + M_PI_8, S_SOUTH},
	{-M_PI_4 - M_PI_8, -M_PI_4 + M_PI_8, S_SOUTH_EAST},};

void vector_comparison(struct s_vector *v1, size_t x, size_t y)
{
	if (sqrt(pow(v1->y, 2) + pow(v1->x, 2)) > sqrt(pow(y, 2) +
		pow(x, 2))) {
		v1->x = x;
		v1->y = y;
	}
}

void short_vector(struct s_vector *v, map_t *map)
{
	vector_t m;
	vector_t origin;

	m.x = (int)map->x;
	m.y = (int)map->y;
	origin = *v;
	vector_comparison(v, origin.x + m.x, origin.y + m.y);
	vector_comparison(v, origin.x + m.x, origin.y - m.y);
	vector_comparison(v, origin.x + m.x, origin.y);
	vector_comparison(v, origin.x - m.x, origin.y + m.y);
	vector_comparison(v, origin.x - m.x, origin.y - m.y);
	vector_comparison(v, origin.x - m.x, origin.y);
	vector_comparison(v, origin.x, origin.y + m.y);
	vector_comparison(v, origin.x, origin.y - m.y);
}

sounddir_t get_s_type(sounddir_t s, int dir)
{
	switch (dir) {
	case NORTH:
		return (s);
	case EAST:
		if (s + 2 > S_NORTH_EAST)
			return (s + 2) % S_NORTH_EAST;
		return (s + 2);
	case SOUTH:
		if (s + 4 > S_NORTH_EAST)
			return (s + 4) % S_NORTH_EAST;
		return (s + 4);
	case WEST:
		if (s + 6 > S_NORTH_EAST)
			return (s + 6) % S_NORTH_EAST;
		return (s + 6);
	default:
		break;
	}
	return (S_NONE);
}

sounddir_t get_s_dir(map_t *map, client_t *d, client_t *origin)
{
	vector_t vector;
	double angle;
	size_t angvar = sizeof(g_variation) / sizeof(*g_variation);

	if (map == NULL || d == NULL || origin == NULL)
		return (S_NONE);
	vector.x = (size_t)(origin->pos_x - d->pos_x);
	vector.y = (size_t)(origin->pos_y - d->pos_y);
	short_vector(&vector, map);
	if (vector.x == 0 && vector.y == 0)
		return (S_NONE);
	if (vector.x == 0)
		return (get_s_type(vector.y <= 0 ? S_SOUTH : S_NORTH, d->dir));
	if (vector.y == 0)
		return (get_s_type(vector.x <= 0 ? S_WEST : S_EAST, d->dir));
	angle = atan2(vector.y, vector.x);
	for (size_t i = 0; i < angvar; i++)
		if (angle >= g_variation[i].min && angle <= g_variation[i].max)
			return (get_s_type(g_variation[i].sound, d->dir));
	return (get_s_type(S_WEST, d->dir));
}

bool broadcast(info_t *serv, client_t *current, char *cmd)
{
	sounddir_t sound;
	char *str;

	if (serv == NULL || serv->clients == NULL || cmd == NULL ||
		strlen(cmd) < 1) {
		return false;
	}

	for (size_t i = 4; i < (serv->nb_client + 4); i++) {
		if (serv->clients[i] == NULL ||
			serv->clients[i]->fd == current->fd) {
			continue;
		}
		sound = get_s_dir(serv->serv.map, serv->clients[i], current);
		str = create_broadcast((int)sound, cmd);
		write(serv->clients[i]->fd, str, strlen(str));
	}
	return true;
}
