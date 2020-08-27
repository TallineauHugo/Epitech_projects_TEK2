/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/main
*/

#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "server.h"

/*
** Fonction qui demiminue la food de chaque joueur dans la partie et qui
** check si chaque player est encore en vie
** Elle est appellée dans server, tous les 126/f
*/

void check_dead_player(info_t *info)
{
	if (info->nb_client > 0) {
		for (size_t i = 4; i <= (3 + info->nb_client); i++) {
			if (info->clients[i]) {
				if (info->clients[i]->pos_x != -1 &&
					info->clients[i]->pos_y != -1) {
					info->clients[i]->inventory.food -= 1;
					if (info->clients[i]->inventory.food <=
						0) {
						write(info->clients[i]->fd,
							"dead\n",
							strlen("dead\n"));
						close_client(info,
							info->clients[i]->fd);
					}
				}
			}
		}
	}
}
