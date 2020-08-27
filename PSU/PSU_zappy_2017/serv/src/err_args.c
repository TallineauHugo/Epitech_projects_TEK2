/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <stdio.h>

int err_freq(short type, char **av)
{
	if (type == 1)
		printf("%s: option requires an argument -- 'f'\n\n", av[0]);
	if (type == 2) {
		printf("\n-f option only accepts integer values ");
		printf("between 2 and 10000\n\n");
	}
	return -1;
}

int err_c_nb(short type, char **av)
{
	if (type == 1)
		printf("%s: option requires an argument -- 'c'\n\n", av[0]);
	if (type == 2) {
		printf("\n-c option only accepts integer values ");
		printf("greater or equal to 1\n\n");
	}
	return -1;
}

int err_hp(short type, char **av)
{
	if (type == 1)
		printf("%s: option requires an argument -- 'y'\n\n", av[0]);
	if (type == 2) {
		printf("\n-y option only accepts integer values ");
		printf("between 10 and 30\n\n");
	}
	return -1;
}

int err_wp(short type, char **av)
{
	if (type == 1)
		printf("%s: option requires an argument -- 'x'\n\n", av[0]);
	if (type == 2) {
		printf("\n-x option only accepts integer values ");
		printf("between 10 and 30\n\n");
	}
	return -1;
}

int err_t(char **av)
{
	printf("%s: option requires an argument -- 'n'\n\n", av[0]);
	return -1;
}
