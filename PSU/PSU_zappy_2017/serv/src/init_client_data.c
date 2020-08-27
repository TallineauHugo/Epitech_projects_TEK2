/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/main
*/

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"

/*
** Fonction d'init de l'inventaire d'un joueur
** /!\ Un joueur commence avec 10 de foos /!\
*/

void init_bag(bag_t *inventory)
{
	inventory->food = 10;
	inventory->linemate = 0;
	inventory->deraumere = 0;
	inventory->sibur = 0;
	inventory->mendiane = 0;
	inventory->phiras = 0;
	inventory->thystame = 0;
}

/*
** Fonction d'initialisation de la structure du joueur en fonction du FD
** Concerné et aussi des pointeurs sur fonctions appelés par le select
*/

void init_client_player(info_t *info, int cs)
{
	info->serv.fd_type[cs] = FD_CLIENT;
	info->serv.fct_read[cs] = client_read;
	info->serv.fct_write[cs] = client_write;
	info->clients[cs] = malloc(sizeof(client_t));
	info->clients[cs]->fd = cs;
	info->clients[cs]->team = false;
	info->clients[cs]->teamName = NULL;
	info->clients[cs]->level = 1;
	info->clients[cs]->pos_x = -1;
	info->clients[cs]->pos_y = -1;
	init_bag(&info->clients[cs]->inventory);
	info->nb_client++;
}

/*
** Fonction d'ajout d'un client côté serveur (accept de la socket et print du)
** message d'arrivée
*/

void add_client(info_t *info, int s)
{
	int cs;
	struct sockaddr_in client_sin;
	int client_sin_len;
	char *str;

	str = malloc(sizeof(char) * 200);
	client_sin_len = sizeof(client_sin);
	cs = accept(s, (struct sockaddr *)&client_sin,
		(socklen_t *)&client_sin_len);
	printf("Client [%d] joined the game\n", cs);
	init_client_player(info, cs);
	sprintf(str, "WELCOME\n");
	write(cs, str, strlen(str));
}

/*
** Fonction qui permet au serveur de détecter l'arrivée d'un nouveau client
*/

void server_read(info_t *e, int fd)
{
	printf("New client\n");
	add_client(e, fd);
}

int define_ip_port(int port, struct sockaddr_in *s_in)
{

	if (port == -1)
		return -1;
	s_in->sin_family = AF_INET;
	s_in->sin_port = htons(port);
	s_in->sin_addr.s_addr = INADDR_ANY;
	return 0;
}