/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "broadcast.h"
#include "proto.h"

void incantation_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)arg;
	(void)info;
	elevation(map, client);
}