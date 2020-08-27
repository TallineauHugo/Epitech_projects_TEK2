/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "vision.h"

char *my_realloc(char *str, const char c[])
{
	char *result;
	int i = 0;
	int y = 0;

	result = malloc((strlen(str) + 1 + strlen(c)) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (str[i] && str[i] != '\0') {
		result[i] = str[i];
		i++;
	}
	while (c[y] != '\0') {
		result[i] = c[y];
		i++;
		y++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}

char *get_loot(bag_t *inventory, char *msg)
{
	int i = 0;

	for (i = 0; i < inventory->food; i++)
		msg = my_realloc(msg, " food");
	for (i = 0; i < inventory->linemate; i++)
		msg = my_realloc(msg, " linemate");
	for (i = 0; i < inventory->deraumere; i++)
		msg = my_realloc(msg, " deraumere");
	for (i = 0; i < inventory->sibur; i++)
		msg = my_realloc(msg, " sibur");
	for (i = 0; i < inventory->mendiane; i++)
		msg = my_realloc(msg, " mendiane");
	for (i = 0; i < inventory->phiras; i++)
		msg = my_realloc(msg, " phiras");
	for (i = 0; i < inventory->thystame; i++)
		msg = my_realloc(msg, " thystame");
	return msg;
}