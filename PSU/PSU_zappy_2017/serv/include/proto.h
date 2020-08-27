/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "struct.h"

int init_socket_s();

int calc_clients_max(info_t *info);

int fill_teams_name(char **av, serv_t *serv);

bool only_digit(char *str);

int my_bind(int, struct sockaddr_in *);

int my_listen(int);

int init_serv(char **, info_t *);

void add_fd(info_t *, int);

void client_connected(int);

void init_client(info_t *);

void remove_fd(int, info_t *);

char *rm_eol(char *);

char *epur(char *);

void handle_client_fd(client_t *);

void update_server(info_t *);

int init_data(char **av, info_t *info);

int nb_teams(char **av);

char **name_teams(char **av);

int find_my_team(info_t *info, client_t *client, char *buff);

void add_player_list(p_manager_t **p_man, client_t *player);

void remove_player_list(p_manager_t **p_man, client_t *player);

p_manager_t *init_player_manager(void);

void check_dead_player(info_t *info);

map_t *init_struct_map(info_t *info, uint32_t width, uint32_t height);

void free_map(map_t *map);

int err_freq(short, char **);

int err_c_nb(short, char **);

int err_hp(short, char **);

int err_wp(short, char **);

int err_port(short, char **);

int err_t(char **);

int get_width_map(char **);

int get_height_map(char **);

size_t get_clients_nb(char **);

size_t get_freq(char **);

/*
** SET FUNCTIONS
*/

void set_mendiane(map_t *map, client_t *client);

void set_sibur(map_t *map, client_t *client);

void set_deraumere(map_t *map, client_t *client);

void set_linemate(map_t *map, client_t *client);

void set_food(map_t *map, client_t *client);

void set_phiras(map_t *map, client_t *client);

void set_thystame(map_t *map, client_t *client);

/*
** TAKE FUNCTIONS
*/

void take_phiras(map_t *map, client_t *client);

void take_thystame(map_t *map, client_t *client);

void take_food(map_t *map, client_t *client);

void take_linemate(map_t *map, client_t *client);

void take_deraumere(map_t *map, client_t *client);

void take_sibur(map_t *map, client_t *client);

void take_mendiane(map_t *map, client_t *client);

void elevation(map_t *map, client_t *client);
