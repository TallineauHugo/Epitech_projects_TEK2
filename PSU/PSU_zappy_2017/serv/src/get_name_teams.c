/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <string.h>
#include <stdlib.h>

int stop01(char *str)
{
	if (strcmp("-p", str) == 0)
		return 0;
	if (strcmp("-x", str) == 0)
		return 0;
	if (strcmp("-y", str) == 0)
		return 0;
	return 84;
}

int stop02(char *str)
{
	if (strcmp("-c", str) == 0)
		return 0;
	if (strcmp("-f", str) == 0)
		return 0;
	return 84;
}

int nb_teams(char **av)
{
	int checkpoint = 0;
	int max = 0;
	int i = 0;
	for (; av[max] != NULL; max++);
	for (; av[i] != NULL; i++) {
		if (strcmp("-n", av[i]) == 0) {
			i++;
			checkpoint = i;
			while ((stop01(av[i]) == 84 && stop02(av[i]) == 84) &&
				i < max - 1)
				i++;
			break;
		}
	}
	return (i - checkpoint);
}

int my_cond(char *str, int i, int max)
{
	if ((stop01(str) == 84 && stop02(str) == 84) && i <= max - 1)
		return 84;
	return 0;
}

char **name_teams(char **av)
{
	char **tab = malloc(sizeof(char *) * (nb_teams(av) + 1));
	int y = 0;
	int max = 0;

	if (tab == NULL)
		return NULL;
	for (; av[max] != NULL; max++);
	for (int i = 0; av[i] != NULL; i++) {
		if (strcmp("-n", av[i]) == 0) {
			i++;
			while (my_cond(av[i], i, max) == 84) {
				tab[y] = strdup(av[i++]);
				if (tab[y++] == NULL)
					return NULL;
			}
			break;
		}
	}
	tab[y] = NULL;
	return tab;
}
