/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

/*
** Initialisation du playerManager
*/

p_manager_t *init_player_manager(void)
{
	p_manager_t *p_m;

	p_m = malloc(sizeof(p_manager_t));
	p_m->players = NULL;
	p_m->next = NULL;
	return p_m;
}

/*
** Remplissage du premier Noeud
*/

void fill_first_list_node(p_manager_t *p_man, client_t *client)
{
	p_man->next = NULL;
	p_man->players = client;
}

/*
** Check si la liste est vide
*/

int list_is_empty(p_manager_t *p_man)
{
	if (p_man == NULL)
		return 0;
	if (p_man->players == NULL)
		return 0;
	else
		return 1;
}

/*
** Ajout d'un player à la liste, on check d'abord si la liste est vide
** Et si non on ajoute le nouveau noeud à la fin
*/

void add_player_list(p_manager_t **p_man, client_t *player)
{
	p_manager_t *tmp = *p_man;
	p_manager_t *last;

	if (!list_is_empty(*p_man))
		return (fill_first_list_node(*p_man, player));
	tmp = malloc(sizeof(p_manager_t));
	tmp->next = NULL;
	tmp->players = player;
	last = *p_man;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
}

/*
** Deletion d'un noeud en fonction du pointeur sur le client
** Afin de delete le bon noeud
*/

void remove_player_list(p_manager_t **p_man, client_t *player)
{
	p_manager_t *tmp = *p_man;
	p_manager_t *prev = *p_man;

	if (tmp == NULL)
		return;
	if (tmp->next == NULL) {
		tmp->players = NULL;
		return;
	}
	while (tmp != NULL && tmp->next != NULL && tmp->players != player) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp != NULL && tmp->players == player) {
		if (tmp->next == NULL)
			prev->next = NULL;
		else
			prev->next = tmp->next;
		free(tmp);
	}
}
