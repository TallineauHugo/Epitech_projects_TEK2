/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "hdl_time.h"
#include "command_handler.h"

/*
** Tableau constant global statique des pointeurs sur fonctions pour les actions du client
*/

const command_func_t g_command_func[] = {{"Forward", &forward_command},
	{"Right", &right_command}, {"Left", &left_command},
	{"Look", &look_command}, {"Inventory", &inventory_command},
	{"Broadcast text", &broadcast_command},
	{"Connect_nbr", &connect_command}, {"Fork", &fork_command},
	{"Eject", &eject_command}, {"Take", &take_command},
	{"Set", &set_command}, {"Incantation", &incantation_command},
	{NULL, NULL}};

/*
** Fonction qui permet d'éxecuter la commande stocké dans la queue d'actions
** et de la faire correspondre avec le bon pointeur sur fonction
*/

void execute_action(action_queue_t *node, int k, info_t *info)
{
	int i;
	(void)k;

	for (i = 0; g_command_func[i].name != NULL; i++) {
		if (!strcmp(g_command_func[i].name, node->action) ||
			((i == 9) &&
				!strncmp(g_command_func[i].name, node->action,
					4)) || ((i == 10) &&
			!strncmp(g_command_func[i].name, node->action, 3))) {
			if (i == 9 || i == 10) {
				g_command_func[i].func(info->serv.map,
					node->client, get_object(node->action),
					info);
			} else
				g_command_func[i].func(info->serv.map,
					node->client, NULL, info);
		}
	}
}

/*
** Fonction qui a pour but de vérifier si la commande reçu est valide et
** si oui, de la stacker dans la queue d'action
*/

void handle_action(char *cmd, action_queue_t *queue, info_t *info, int fd)
{
	int i;
	bool valid = false;

	for (i = 0; g_command_func[i].name != NULL; i++) {
		if (!strcmp(g_command_func[i].name, cmd) ||
			!strncmp("Take", cmd, 4) || !strncmp("Set", cmd, 3))
			valid = true;
	}
	if (valid == false)
		dprintf(info->clients[fd]->fd,
			"ko (Invalid cmd:\"%s\" no such command)\n", cmd);
	else {
		if (!strcmp("Incantation", cmd))
			dprintf(info->clients[fd]->fd, "Elevation underway\n");
		add_action_queue(&queue, cmd, info->serv.freq,
			info->clients[fd]);
	}
}
