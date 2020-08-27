/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#pragma once

#include "hdl_time.h"
#include "struct.h"

typedef struct command_func_s {
	char *name;

	void (*func)(map_t *map, client_t *client, char *arg, info_t *);
} command_func_t;

void execute_action(action_queue_t *node, int k, info_t *info);

int is_queue_empty(action_queue_t *queue);

int check_action(action_queue_t *queue, hdl_time_t *handleTime);

void handle_action(char *cmd, action_queue_t *queue, info_t *info, int fd);

/*
** Client Functions
*/

void move_client(client_t *client, map_t *map);

void forward_command(map_t *map, client_t *client, char *arg, info_t *);

void right_command(map_t *map, client_t *client, char *arg, info_t *);

void left_command(map_t *map, client_t *client, char *arg, info_t *);

void look_command(map_t *map, client_t *client, char *arg, info_t *);

void inventory_command(map_t *map, client_t *client, char *arg, info_t *);

void broadcast_command(map_t *map, client_t *client, char *arg, info_t *);

void connect_command(map_t *map, client_t *client, char *arg, info_t *);

void fork_command(map_t *map, client_t *client, char *arg, info_t *);

void eject_command(map_t *map, client_t *client, char *arg, info_t *);

void take_command(map_t *map, client_t *client, char *arg, info_t *);

void set_command(map_t *map, client_t *client, char *arg, info_t *);

void incantation_command(map_t *map, client_t *client, char *arg, info_t *);
