/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hdl_time.h"
#include "command_handler.h"

/*
** Fonction qui permet de récupérer un pointeur sur le noeud voulu, en fonction
** du numéro du noeud (qui est calculé via la fonction check_ended_action())
*/

action_queue_t *get_node(action_queue_t *queue, int i)
{
	int cpt = -1;
	action_queue_t *tmp = queue;

	if (queue == NULL || !is_queue_empty(queue))
		return NULL;
	if (i == 0)
		return queue;
	while (tmp->next != NULL && ++cpt < i)
		tmp = tmp->next;
	if (tmp == NULL || cpt != i)
		return NULL;
	return tmp;
}

/*
** Deletion d'un noeud de la queue
*/

void delete_first_node(action_queue_t **queue, action_queue_t *tmp)
{
	*queue = tmp->next;
	tmp->start = NULL;
	tmp->end = NULL;
	tmp->action = NULL;
	tmp->client = NULL;
	free(tmp->start);
	free(tmp->end);
	free(tmp->action);
	display_action_queue(*queue);
}

void delete_node_action(action_queue_t **queue, int i)
{
	action_queue_t *tmp = *queue;
	action_queue_t *prev = *queue;
	int cpt = -1;

	if (tmp != NULL && i == 0)
		return delete_first_node(queue, tmp);
	while (tmp != NULL && ++cpt < i) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return;
	if (tmp->next != NULL)
		prev->next = tmp->next;
	else
		prev->next = NULL;
	free(tmp->start);
	free(tmp->end);
	free(tmp->action);
	tmp->client = NULL;
}

/*
** Fonction qui permet de checker en temps réel si une action est terminée,
** Elle s'appuie sur l'heure actuelle exacte et parcours la queue afin de voir les actions terminées
** Dés lors qu'une action est effectuée (via execute_action()), le noeud qui la concerne
** est supprimé
*/

void end_first_action(action_queue_t **queue, action_queue_t *tmp, info_t *info, hdl_time_t *handletime)
{
	if (tmp != NULL && tmp->next != NULL) {
		if (!check_action(tmp, handletime)) {
			execute_action(get_node(tmp, 0), 0, info);
			delete_node_action(&tmp, 0);
		} else
			*queue = tmp;
	}
	if (tmp != NULL && tmp->next == NULL) {
		if (!check_action(tmp, handletime)) {
			execute_action(get_node(tmp, 0), 0, info);
			delete_node_action(&tmp, 0);
		} else
			*queue = tmp;
	}
}

void check_ended_action(action_queue_t **queue, info_t *info)
{
	action_queue_t *tmp;
	static hdl_time_t *handletime;

	if (handletime == NULL)
		handletime = get_current_time();
	update_current_time(handletime);
	if (*queue == NULL && !is_queue_empty(*queue)) {
		return;
	}
	tmp = *queue;
	end_first_action(queue, tmp, info, handletime);
}
