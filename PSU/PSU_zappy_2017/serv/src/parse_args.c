/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "proto.h"

int get_port(char **av)
{
	int i = 0;
	int max = 0;
	int default_val = 4242;
	int val = 0;

	while (av[max] != NULL)
		max++;
	while (av[i] != NULL) {
		if (i <= max - 1 && strcmp("-p", av[i]) == 0) {
			if (av[i + 1] == NULL)
				return err_port(1, av);
			val = atoi(av[i + 1]);
			if (only_digit(av[i + 1]) == false || val < 0)
				return err_port(2, av);
			return val;
		}
		i++;
	}
	return default_val;
}

int get_width_map(char **av)
{
	int i = 0;
	int max = 0;
	size_t default_val = 10;
	size_t val = 0;

	while (av[max] != NULL)
		max++;
	while (av[i] != NULL) {
		if (i <= max - 1 && strcmp("-x", av[i]) == 0) {
			if (av[i + 1] == NULL)
				return err_wp(1, av);
			val = (size_t)atol(av[i + 1]);
			if (only_digit(av[i + 1]) == false ||
				(val < 10 || val > 30))
				return err_wp(2, av);
			return val;
		}
		i++;
	}
	return default_val;
}

int get_height_map(char **av)
{
	int i = 0;
	int max = 0;
	size_t default_val = 10;
	size_t val = 0;

	while (av[max] != NULL)
		max++;
	while (av[i] != NULL) {
		if (i <= max - 1 && strcmp("-y", av[i]) == 0) {
			if (av[i + 1] == NULL)
				return err_hp(1, av);
			val = (size_t)atol(av[i + 1]);
			if (only_digit(av[i + 1]) == false ||
				(val < 10 || val > 30))
				return err_hp(2, av);
			return val;
		}
		i++;
	}
	return default_val;
}

size_t get_clients_nb(char **av)
{
	int i = 0;
	int max = 0;
	size_t default_val = 3;
	size_t val = 0;

	while (av[max] != NULL)
		max++;
	while (av[i] != NULL) {
		if (i <= max - 1 && strcmp("-c", av[i]) == 0) {
			if (av[i + 1] == NULL)
				return err_c_nb(1, av);
			val = (size_t)atol(av[i + 1]);
			if (only_digit(av[i + 1]) == false || val < 1)
				return err_c_nb(2, av);
			return val;
		}
		i++;
	}
	return default_val;
}

size_t get_freq(char **av)
{
	int i = 0;
	int max = 0;
	size_t default_val = 100;
	size_t val = 0;

	while (av[max] != NULL)
		max++;
	while (av[i] != NULL) {
		if (i <= max - 1 && strcmp("-f", av[i]) == 0) {
			if (av[i + 1] == NULL)
				return err_freq(1, av);
			val = (size_t)atol(av[i + 1]);
			if (only_digit(av[i + 1]) == false ||
				(val < 2 || val > 10000))
				return err_freq(2, av);
			return val;
		}
		i++;
	}
	return default_val;
}
