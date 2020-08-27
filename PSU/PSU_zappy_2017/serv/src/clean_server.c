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
** Fonction de destruction des ressources de la queue
*/

void destroy_queue(action_queue_t **queue)
{
	action_queue_t *tmp = *queue;
	action_queue_t *prev;

	while (tmp->next != NULL) {
		prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
	if (tmp != NULL)
		free(tmp);
}

/*
** Fonction de clean du serveur (à la réception d'un SIGINT côté serveur)
*/

void clean_it(info_t *en)
{
	int i;
	int j;

	for (i = 0; i < MAX_FD; i++) {
		if (en->serv.fd_type[i] != FD_FREE) {
			close(i);
		}
	}
	for (i = 0; (size_t)i < en->serv.map->x; i++) {
		for (j = 0; (size_t)j < en->serv.map->y; j++) {
			if (en->serv.map->map[i][j].players)
				free(en->serv.map->map[i][j].players);
			free(en->serv.map->map[i][j].inventory);
		}
		free(en->serv.map->map[i]);
	}
}

void server_cleaner(info_t *e, action_queue_t *queue)
{
	static info_t *en;
	static action_queue_t *queuen;

	if (e && queue) {
		en = e;
		queuen = queue;
	} else {
		clean_it(en);
		free(en->clients);
		free(en->serv.map);
		destroy_queue(&queuen);
		printf("  Server closed properly\n");
		exit(0);
	}
}