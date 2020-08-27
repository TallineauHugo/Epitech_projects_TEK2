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

int init_socket_s(void)
{
	struct protoent *protocol;
	int s_s;
	int flags;

	protocol = getprotobyname("TCP");
	if (!protocol)
		return -1;
	s_s = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
	if (s_s == -1)
		return -1;
	flags = fcntl(s_s, F_GETFL);
	if (flags == -1)
		return -1;
	if (fcntl(s_s, F_SETFL, flags | O_NONBLOCK))
		return -1;
	return s_s;
}

int my_bind(int s_s, struct sockaddr_in *s_in, serv_t *serv)
{
	socklen_t addr_len;

	if (bind(s_s, (const struct sockaddr *)&(*s_in), sizeof(*s_in)) == -1) {
		perror("[ERROR] : bind ");
		if (close(s_s) == -1)
			return -1;
		return -2;
	}
	addr_len = sizeof(*s_in);
	if (getsockname(s_s, (struct sockaddr *)&(*s_in), &addr_len) == -1) {
		perror("[ERROR] : sockname ");
		dprintf(2, "\n");
		if (close(s_s) == -1)
			return -1;
		return -1;
	}
	serv->port = s_in->sin_port;
	printf("Port : %d\n", ntohs(s_in->sin_port));
	return 0;
}

int my_listen(int s_s)
{
	if (listen(s_s, NB_MAX_CLIENT) == -1) {
		if (close(s_s) == -1)
			return -1;
		return -1;
	}
	return 0;
}

/*
** Fonction d'initialisation du serveur
*/

int add_server(info_t *info, char **av)
{
	struct sockaddr_in sin;

	info->serv.fd = init_socket_s();
	if (info->serv.fd == -1 || define_ip_port(get_port(av), &(sin)) == -1)
		return -1;
	if (my_bind(info->serv.fd, &(sin), &info->serv) == -2 ||
		my_listen(info->serv.fd) == -1)
		return -2;
	info->serv.fd_type[info->serv.fd] = FD_SERVER;
	info->serv.fct_read[info->serv.fd] = server_read;
	info->serv.fct_write[info->serv.fd] = NULL;
	info->nb_client = 0;
	return 0;
}
