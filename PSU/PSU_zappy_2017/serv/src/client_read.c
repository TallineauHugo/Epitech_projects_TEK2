/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/main
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "server.h"
#include "proto.h"

/*
** Fonction appellée lorsque le client envoie un message au update_server
** Elle check si le client est dans une team et si oui, elle traite son message
** Cette fonction permet aussi de savoir si une socket est fermée par le client
** (CTRL-L via le client)
*/

void client_read(info_t *info, int fd, action_queue_t *queue)
{
	int r, i;
	char buf[4096];
	list_cmd_t cmd;

	memset(buf, '\0', 4096);
	r = read(fd, buf, 4096);
	if (r > 0) {
		buf[r] = '\0';
		get_cmd_list(buf, &cmd);
		for (i = 0; i < cmd.nb_cmd; i++) {
			if (info->clients[fd]->team == false)
				find_my_team(info, info->clients[fd],
					cmd.list[i]);
			else
				handle_action(cmd.list[i], queue, info, fd);
			free(cmd.list[i]);
		}
		free(cmd.list);
	} else
		close_client(info, fd);
}