/*
** EPITECH PROJECT, 2018
** philo
** File description:
** setup
*/

#include <pthread.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "setup.h"

void process(data_t *data)
{
	int i = 0;

	while (i < data->nb_philo)
		pthread_join((g_philo[i++].thread), NULL);
}

void init_data(data_t *data)
{
	int i = 0;

	while (i < data->nb_philo) {
		g_philo[i].id = i;
		g_philo[i].cur_state = REST;
		g_philo[i].rest_time = 1300;
		g_philo[i].think_time = 1000;
		g_philo[i].eat_time = 1500;
		g_philo[i].nb_eat = (i == 0) ?
			data->max_loop : data->max_loop - 1;
		g_philo[i].nb_philo = data->nb_philo;
		pthread_create(&(g_philo[i].thread), NULL, brainstorm,
				&g_philo[i]);
		usleep(100);
		i++;
	}
}

bool setup(data_t *data)
{
	int i = 0;

	g_philo = malloc(sizeof(philosopher_t) *
			(data->nb_philo));
	g_mutex = malloc(sizeof(pthread_mutex_t) *
			(data->nb_philo));
	if (!g_mutex || !g_philo)
		return (false);
	while (i < data->nb_philo)
		pthread_mutex_init(&(g_mutex[i++]), NULL);
	init_data(data);
	return (true);
}
