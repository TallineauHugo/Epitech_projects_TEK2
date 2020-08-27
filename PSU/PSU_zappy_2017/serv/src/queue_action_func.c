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
** DEBUGG FUNCTION, affichage de la queue
*/

void display_node(action_queue_t *tmp)
{
	printf("Action = \'%s\'\n", tmp->action);
	printf("start = {h: %ld, min: %ld, sec: %ld, usec: %d}\n\t",
		tmp->start->hour, tmp->start->min, tmp->start->sec,
		tmp->start->usec);
	printf("end = {h: %ld, min: %ld, sec: %ld, usec: %d}\n", tmp->end->hour,
		tmp->end->min, tmp->end->sec, tmp->end->usec);
}

void display_action_queue(action_queue_t *queue)
{
	action_queue_t *tmp;

	if (queue == NULL)
		return;
	if (!is_queue_empty(queue))
		return;
	tmp = queue;
	while (tmp->next != NULL) {
		display_node(tmp);
		tmp = tmp->next;
	}
	display_node(tmp);
}
