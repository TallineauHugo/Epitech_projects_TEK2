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
** Fonction qui s'occupe de la boucle du serveur, du timer des actions et de la
** mort des joueurs
*/

void loop_server(fd_set fd_read, info_t *info, action_queue_t *queue)
{
	int i;

	for (i = 0; i <= MAX_FD; i++) {
		if (FD_ISSET(i, &fd_read))
			info->serv.fct_read[i](info, i, queue);
	}
	check_ended_action(&queue, info);
}