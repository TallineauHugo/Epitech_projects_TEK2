/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/broadcast
*/

#include <stdlib.h>
#include "broadcast.h"

char *int_to_str(int nb)
{
	char *dest;
	int i = 0;

	while (nb >= 10) {
		nb /= 10;
		i++;
	}
	dest = malloc(sizeof((*dest) * (i + 1)));
	sprintf(dest, "%d", nb);
	return (dest);
}

char *create_broadcast(int dir, char *cmd)
{
	size_t length = strlen("message ") + strlen(cmd);
	char *dest;

	length += strlen(int_to_str(dir));
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL || cmd == NULL)
		return (NULL);
	dest = strdup(strcat(strdup("message "), strdup(int_to_str(dir))));
	dest = strcat(dest, ", ");
	dest = strcat(dest, cmd);
	dest = strcat(dest, "\n");
	return dest;
}