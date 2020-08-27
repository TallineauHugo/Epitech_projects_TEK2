/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "broadcast.h"
#include "proto.h"

void take_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)map;
	(void)arg;
	(void)info;
	if (!strcmp(arg, "food"))
		take_food(map, client);
	else if (!strcmp(arg, "sibur"))
		take_sibur(map, client);
	else if (!strcmp(arg, "deraumere"))
		take_deraumere(map, client);
	else if (!strcmp(arg, "linemate"))
		take_linemate(map, client);
	else if (!strcmp(arg, "phiras"))
		take_phiras(map, client);
	else if (!strcmp(arg, "thystame"))
		take_thystame(map, client);
	else if (!strcmp(arg, "mendiane"))
		take_mendiane(map, client);
	else
		write(client->fd, "ko\n", strlen("ko\n"));
}

void set_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	(void)map;
	(void)arg;
	(void)info;
	if (!strcmp(arg, "food"))
		set_food(map, client);
	else if (!strcmp(arg, "sibur"))
		set_sibur(map, client);
	else if (!strcmp(arg, "deraumere"))
		set_deraumere(map, client);
	else if (!strcmp(arg, "linemate"))
		set_linemate(map, client);
	else if (!strcmp(arg, "phiras"))
		set_phiras(map, client);
	else if (!strcmp(arg, "thystame"))
		set_thystame(map, client);
	else if (!strcmp(arg, "mendiane"))
		set_mendiane(map, client);
	else
		write(client->fd, "ko\n", strlen("ko\n"));
}