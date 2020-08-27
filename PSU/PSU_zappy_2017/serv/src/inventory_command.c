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

void inventory_command(map_t *map, client_t *client, char *arg, info_t *info)
{
	char *str = malloc(sizeof(char) * 1000);
	(void)map;
	(void)arg;
	(void)info;
	sprintf(str, "[ food %d, linemate %d, deraumere %d, sibur %d, mendiane"
			" %d, phiras %d, "
			"thystame %d ]\n", client->inventory.food,
		client->inventory.linemate, client->inventory.deraumere,
		client->inventory.sibur, client->inventory.mendiane,
		client->inventory.phiras, client->inventory.thystame);
	write(client->fd, str, strlen(str));
	free(str);
}
