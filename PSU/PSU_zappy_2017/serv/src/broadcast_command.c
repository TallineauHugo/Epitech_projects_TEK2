/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "broadcast.h"

void broadcast_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)map;
	broadcast(info, client, arg);
}