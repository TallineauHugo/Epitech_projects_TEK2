/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#pragma once

#include <sys/types.h>
#include "struct.h"

typedef struct time_action_s {
	char *action;
	size_t time_unit;
} time_action_t;

typedef struct time_s {
	size_t year;
	size_t day;
	size_t hour;
	size_t min;
	size_t sec;
	unsigned int usec;
} hdl_time_t;

typedef struct action_queue_s {
	client_t *client;
	hdl_time_t *start;
	hdl_time_t *end;
	char *action;
	struct action_queue_s *next;
} action_queue_t;

void fill_time(hdl_time_t *handleTime, struct timeval *tv);

hdl_time_t *time_struct_cpy(hdl_time_t *handleTime);

hdl_time_t *get_current_time(void);

hdl_time_t *calcul_end_time(hdl_time_t *start, char *action, size_t frequency);

hdl_time_t *calcul_start_time(action_queue_t *queue, client_t *client);

void add_action_queue(action_queue_t **queue, char *action, size_t frequency,
	client_t *client
);

action_queue_t *init_queue(void);

void display_action_queue(action_queue_t *queue);

void check_ended_action(action_queue_t **queue, info_t *info);

void delete_node_action(action_queue_t **queue, int i);

void update_current_time(hdl_time_t *handleTime);

char *get_first_cmd(char *action);

char *get_object(char *action);
