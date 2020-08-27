/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#pragma once

#include <stdbool.h>
#include <unistd.h>
#include "macro.h"

enum dir {
	UP,
	LEFT,
	DOWN,
	RIGHT
};

typedef struct s_bag {
	int food;
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystame;
} bag_t;

typedef struct s_client {
	int fd;
	int pos_x;
	int pos_y;
	short level;
	bag_t inventory;
	bool team;
	enum dir dir;
	char *teamName;
} client_t;

typedef struct s_team {
	char *name;
	client_t **players;
	size_t nb_p;
} team_t;

typedef struct s_p_manager {
	client_t *players;
	struct s_p_manager *next;
} p_manager_t;

typedef struct cell_s {
	int nb_players;
	int nb_loot;
	bag_t *inventory;
	p_manager_t *players;
} cell_t;

typedef struct map_s {
	size_t x;
	size_t y;
	cell_t **map;
} map_t;

typedef struct s_serv {
	int fd;
	size_t nb_players_team;
	int nb_t;
	team_t *team_list;
	map_t *map;
	int freq;
	char fd_type[MAX_FD];
	fct_t fct_read[MAX_FD];
	fct_t fct_write[MAX_FD];
	int port;
} serv_t;

typedef struct s_info {
	serv_t serv;
	size_t max_clients;
	client_t **clients;
	size_t nb_client;
} info_t;
