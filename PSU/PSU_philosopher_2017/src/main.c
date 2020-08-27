/*
** EPITECH PROJECT, 2018
** philo
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "macro.h"
#include "parse_arguments.h"
#include "setup.h"
#include "data.h"
#include "extern.h"

static int disp_usage(char *str, int ret)
{
	printf("USAGE\n\t%s -p nbr_p -e nbr_e\n\nDESCRIPTION\n\t", str);
	printf("-p nbr_p number of philosophers\n\t-e nbr_e maximum number ");
	printf("times a philosopher eats before exiting the program\n");
	return (ret);
}

int main(int ac, char **av)
{
	data_t data;

	RCFStartup(ac, av);
	srand(time(NULL));
	if (ac == 2 && strcmp(av[1], HELP))
		return (disp_usage(av[0], 0));
	if (!get_arguments(ac, av, &data))
		return (disp_usage(av[0], 84));
	if (!setup(&data))
		return (84);
	process(&data);
	RCFCleanup();
	return (0);
}
