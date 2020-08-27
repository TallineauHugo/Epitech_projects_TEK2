/*
** EPITECH PROJECT, 2018
** philo
** File description:
** philo
*/

#pragma once

#include <pthread.h>
#include "setup.h"

enum state {
	EAT,
	REST,
	THINK
};

typedef enum state e_state;

struct philosopher
{
	size_t id;
	e_state cur_state;
	int rest_time;
	int think_time;
	int eat_time;
	int nb_eat;
	int nb_philo;
	pthread_t thread;
};

typedef struct philosopher philosopher_t;

void *brainstorm(void*);

extern philosopher_t *g_philo;
extern pthread_mutex_t *g_mutex;
