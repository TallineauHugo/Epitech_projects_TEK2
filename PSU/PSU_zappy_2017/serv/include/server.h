/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** include
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "struct.h"
#include "command_handler.h"
#include "macro.h"

typedef struct list_cmd_t {
	int nb_cmd;
	char **list;
} list_cmd_t;

/* SERVER FUNCTIONS */
void server_read(info_t *e, int fd);

int add_server(info_t *e, char **av);

void client_write(int fd, char *buf);

void client_read(info_t *info, int fd, action_queue_t *action);

void close_client(info_t *info, int fd);

int server(char **argv, info_t *info);

void get_cmd_list(const char *buf, list_cmd_t *cmd);

char *get_cmd(char *sent);

void add_client(info_t *e, int s);

int check_empty(char *str);

int define_ip_port(int port, struct sockaddr_in *s_in);

void server_cleaner(info_t *e, action_queue_t *queue);

void loop_server(fd_set fd_read, info_t *info, action_queue_t *queue);

void unknown_cmd(int fd, char *str);

char *get_param(char *str);

int get_port(char **);

#endif
