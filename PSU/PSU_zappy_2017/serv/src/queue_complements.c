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
** init de la queue
*/

action_queue_t *init_queue(void)
{
	action_queue_t *queue;

	queue = malloc(sizeof(action_queue_t));
	queue->next = NULL;
	queue->start = NULL;
	queue->end = NULL;
	queue->action = NULL;
	queue->client = NULL;
	return queue;
}

/*
** Check si la queue est vide ou nulle
*/

int is_queue_empty(action_queue_t *queue)
{
	if (queue == NULL)
		return 0;
	if (queue->start == NULL || queue->end == NULL)
		return 0;
	else
		return 1;
}

/*
** Remplissage du premier noeud
*/

void fill_first_node(action_queue_t *queue, char *action, size_t frequency,
	client_t *client
)
{
	queue->next = NULL;
	queue->start = get_current_time();
	queue->end = calcul_end_time(queue->start, action, frequency);
	queue->action = strdup(action);
	queue->client = client;
	display_action_queue(queue);
}

/*
** Ajout d'un noeud à la queue, on vérifie d'abord qu'elle n'est pas vide/nulle
** Si oui, on rempli le premier noeud, sinon on ajoute le noeud à la fin de la queue
*/

void add_action_queue(action_queue_t **queue, char *action, size_t frequency,
	client_t *client
)
{
	action_queue_t *tmp;
	action_queue_t *last;

	if (!is_queue_empty(*queue))
		return (fill_first_node(*queue, action, frequency, client));
	tmp = (action_queue_t *)malloc(sizeof(action_queue_t));
	if (tmp == NULL)
		exit(84);
	tmp->next = NULL;
	tmp->start = calcul_start_time(*queue, client);
	tmp->end = calcul_end_time(tmp->start, action, frequency);
	tmp->action = strdup(action);
	tmp->client = client;
	last = *queue;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	display_action_queue(*queue);
}

/*
** KEEP LES PRINTFS DE DEBBUG POUR LE MOMENT
*/

/*
** Comparaison de la structure de temps du noeud avec le temps actuel
** Afin de savoir si l'action est terminée et donc si l'on doit l'executer
*/

int check_action(action_queue_t *queue, hdl_time_t *handleTime)
{
	if (!is_queue_empty(queue) || handleTime == NULL) {
		return 1;
	}
	return 0;
}