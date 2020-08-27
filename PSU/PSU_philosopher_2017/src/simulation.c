/*
** EPITECH PROJECT, 2018
** philo
** File description:
** simulation
*/

#include <stdio.h>
#include <unistd.h>
#include "data.h"
#include "philosopher.h"
#include "extern.h"

philosopher_t *g_philo;
pthread_mutex_t *g_mutex;

void rest(philosopher_t *p);

void eat(philosopher_t *p)
{
	p->cur_state = EAT;
	lphilo_eat();
	p->nb_eat--;
	usleep(p->eat_time);
	pthread_mutex_unlock(&(g_mutex[p->id]));
	pthread_mutex_unlock(&(g_mutex[(p->id + 1) % p->nb_philo]));
	lphilo_release_chopstick(&(g_mutex[p->id]));
	lphilo_release_chopstick(&(g_mutex[(p->id + 1) % p->nb_philo]));
	rest(p);
}

void think(philosopher_t *p)
{
	lphilo_think();
	usleep(p->think_time);
	lphilo_take_chopstick(&(g_mutex[(p->id + 1) % p->nb_philo]));
	eat(p);
}

void rest(philosopher_t *p)
{
	if (p->cur_state == REST)
		return;
	p->cur_state = REST;
	lphilo_sleep();
	usleep(p->rest_time);
}

void *brainstorm(void *arg)
{
	philosopher_t *p;
	int left;
	int right;

	p = (philosopher_t*)arg;
	while (p->nb_eat > 0) {
		left = pthread_mutex_trylock(&(g_mutex[p->id]));
		if (!left)
			right = pthread_mutex_trylock(
				&(g_mutex[(p->id + 1) % p->nb_philo]));
		else
			pthread_mutex_unlock(&(g_mutex[p->id]));
		if (left == 0 && right == 0) {
			lphilo_take_chopstick(&(g_mutex[p->id]));
			think(p);
		}
	}
	return (NULL);
}
