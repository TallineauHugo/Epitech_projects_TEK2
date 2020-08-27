/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/main
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "server.h"
#include "broadcast.h"

/*
** Fonction de détection SIGINT qui permet de call la fonction de cleanserver
*/

static void int_handler(int sig)
{
	(void)sig;
	server_cleaner(0, 0);
}

int read_it(serv_t *e, fd_set *fd_read, int fd_max)
{
	FD_ZERO(fd_read);
	fd_max = 0;
	for (int i = 0; i < MAX_FD; i++) {
		if (e->fd_type[i] != FD_FREE) {
			FD_SET(i, fd_read);
			fd_max = i;
		}
	}
	return (fd_max);
}


/*
** Fonction qui permet d'appliqué la fréquence au timer du select, tmps réel
*/

void apply_freq(struct timeval *tv, double freq)
{
	freq = 1 / freq;
	if (freq >= 1) {
		tv->tv_sec += (size_t)freq;
		freq -= (size_t)freq;
	}
	if (freq > 0.0f) {
		freq *= 1000000;
		tv->tv_usec += freq;
	}
}

int run_server(fd_set fd_read, info_t *info, action_queue_t *queue)
{
	int fd_max = 0;
	struct timeval tv;

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	apply_freq(&tv, info->serv.freq);
	while (1) {
		fd_max = read_it(&info->serv, &fd_read, fd_max);
		if (select(fd_max + 1, &fd_read, NULL, NULL, &tv) == -1) {
			perror("select");
			return 84;
		}
		loop_server(fd_read, info, queue);
		if (tv.tv_sec <= 0 && tv.tv_usec <= 0)
			apply_freq(&tv, info->serv.freq);
	}
}

/*
** Fonction qui permet d'initialiser le serveur, la queue, préparer le catch
**  SIGINT puis de lancer le serveur
*/

int server(char **argv, info_t *info)
{
	fd_set fd_read;
	action_queue_t *queue;
	int err = 0;

	memset(info->serv.fd_type, FD_FREE, MAX_FD);
	err = add_server(info, argv);
	if (err == -1 || err == -2)
		return -1;
	queue = init_queue();
	server_cleaner(info, queue);
	signal(SIGINT, int_handler);
	return (run_server(fd_read, info, queue));
}
