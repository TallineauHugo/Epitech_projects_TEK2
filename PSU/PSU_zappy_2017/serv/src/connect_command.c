/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "broadcast.h"

void connect_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)map;
	(void)arg;
	(void)info;
	write(client->fd, "ko\n", strlen("ko\n"));
}