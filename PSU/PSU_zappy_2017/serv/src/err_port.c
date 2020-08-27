/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <stdio.h>

int err_port(short type, char **av)
{
	if (type == 1)
		printf("%s: option requires an argument -- 'p'\n\n", av[0]);
	if (type == 2) {
		printf("\n-p option only accepts valid ports\n\n");
	}
	return -1;
}