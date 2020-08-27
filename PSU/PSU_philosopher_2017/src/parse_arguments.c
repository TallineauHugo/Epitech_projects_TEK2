/*
** EPITECH PROJECT, 2018
** philo
** File description:
** parser
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parse_arguments.h"
#include "macro.h"

bool save_arguments(data_t *data, char *flag, char *str)
{
	if (!strcmp(flag, NBR_P)) {
		data->nb_philo = atoi(str);
		if (data->nb_philo < MIN_PHILO_NBR) {
			fprintf(stderr, INVALID_PHILO_NBR);
			return (false);
		}
	}
	else if (!strcmp(flag, NBR_E)) {
		data->max_loop = atoi(str);
		if (data->max_loop < MIN_LOOP_NBR) {
			fprintf(stderr, INVALID_NBR_LOOP);
			return (false);
		}
	}
	return (true);
}

bool get_arguments(int ac, char **av, data_t *data)
{
	if (ac != 5 || (av[1][0] != FLAG_PREFIXE) || av[3][0] != FLAG_PREFIXE)
		return (false);
	if (strcmp(av[1], NBR_P) || strcmp(av[1], NBR_E))
		if (!save_arguments(data, av[1], av[2]))
			return (false);
	if (strcmp(av[3], NBR_P) || strcmp(av[3], NBR_E))
		if (!save_arguments(data, av[3], av[4]))
			return (false);
	return (true);
}
