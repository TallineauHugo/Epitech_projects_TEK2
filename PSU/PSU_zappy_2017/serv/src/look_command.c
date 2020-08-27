/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "broadcast.h"
#include "vision.h"

void look_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)map;
	(void)arg;
	(void)info;
	char *res = look(map, client);
	res = my_realloc(res, "\n\0");
	write(client->fd, res, strlen(res));
	free(res);
}