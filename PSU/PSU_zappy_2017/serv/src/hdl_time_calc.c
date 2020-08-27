/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <string.h>
#include <stdio.h>
#include "hdl_time.h"

/*
** Tableau de struct pour savoir le temps associé à chaque action
*/

const time_action_t g_time_action[] = {{"Forward", 7}, {"Right", 7},
	{"Left", 7}, {"Look", 7}, {"Inventory", 1}, {"Broadcast text", 7},
	{"Connect_nbr", 0}, {"Fork", 42}, {"Eject", 7}, {"Take", 7}, {"Set", 7},
	{"Incantation", 300}, {NULL, 0}};

/*
** Fonction qui permet de savoir de quelle fonction du tableau il s'agit
*/

int get_func(char *action)
{
	int i;

	for (i = 0; g_time_action[i].action != NULL; i++) {
		if (!strcmp(action, g_time_action[i].action) || ((i == 9) &&
			!strncmp(action, g_time_action[i].action, 4)) ||
			((i == 10) &&
				!strncmp(action, g_time_action[i].action, 3)))
			return i;
	}
	return -1;
}

/*
** Fonction d'application de la différence afin d'estimer le temps de fin d'une action
** Appellée par calcul_end_time()
*/

hdl_time_t *handle_time_diff(hdl_time_t *end, double diff)
{
	if (diff >= 1) {
		end->sec += diff;
		while (end->sec >= 60) {
			end->min += 1;
			end->sec -= 60;
		}
		diff -= (size_t)diff;
	}
	if (diff > 0.0f) {
		diff *= 1000000;
		end->usec += diff;
	}
	return end;
}

/*
** Fonction de calcul du début d'une action, en fonction des autres actions
** du même client dans la stack de queue d'action
*/

hdl_time_t *calcul_start_time(action_queue_t *queue, client_t *client)
{
	int check = 0;
	action_queue_t *save;
	action_queue_t *tmp = queue;

	while (tmp->next != NULL) {
		if (client->fd == tmp->client->fd) {
			save = tmp;
			check = 1;
		}
		tmp = tmp->next;
	}
	if (client->fd == tmp->client->fd) {
		save = tmp;
		check = 1;
	}
	if (check)
		return save->end;
	else
		return get_current_time();
}

/*
** Fonction de calcul du temps de fin d'une action en fonction de son début
*/

hdl_time_t *calcul_end_time(hdl_time_t *start, char *action, size_t frequency)
{
	hdl_time_t *end = NULL;
	int i;
	double timeDifference;

	end = time_struct_cpy(start);
	i = get_func(action);
	if (i == -1)
		return NULL;
	timeDifference =
		(double)g_time_action[i].time_unit / (double)frequency;
	end = handle_time_diff(end, timeDifference);
	return end;
}
