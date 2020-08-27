/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "server.h"

/*
** Fonction qui permet de découper plusieurs commandes à chaque \n
** permet la gestion d'un envoie de plusieurs commandes simultanées
*/

void init_cmd(list_cmd_t *cmd)
{
	cmd->nb_cmd = 0;
	cmd->list = malloc(sizeof(char *) * 30);
	cmd->list[0] = malloc(100);
	memset(cmd->list[0], '\0', 100);
}

void get_cmd_list(const char *buf, list_cmd_t *cmd)
{
	int i = 0;
	int j = 0;
	int k = 0;

	init_cmd(cmd);
	while (buf[i] != '\0') {
		if (buf[i] == '\n') {
			cmd->nb_cmd++;
			cmd->list[j++][k] = '\0';
			k = 0;
			cmd->list[j] = malloc(100);
			memset(cmd->list[j], '\0', 100);
			i += 1;
		}
		cmd->list[j][k++] = buf[i++];
	}
	cmd->list[j++][k] = '\0';
	cmd->list[j] = NULL;
}
