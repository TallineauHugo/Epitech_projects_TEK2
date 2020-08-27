/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include "hdl_time.h"
#include "proto.h"
#include "server.h"
#include <string.h>

int print_usage(void)
{
	printf("USAGE:\t./zappy_server -p port -x width -y height -n name1 ");
	printf("name2 ... -c clientsNb -f freq\n");
	printf("\tport\t\tis the port number\n\twidth\t\tis the width of");
	printf(" the world\n\theight\t\tis the height ");
	printf("of the world\n\tnameX\t\tis the name of the team X\n\t");
	printf("clientsNb\tis the number of authorized clients per team\n\t");
	printf("freq\t\tis the reciprocal of time unit fo execution of");
	printf(" actions\n");
	return 84;
}

/*
** Main function: On init d'abord la structure info, puis via la fonction serveur
** on init le serveur et on le lance 
*/

int main(int ac, char **av)
{
	info_t info;
	int err = 0;
	int err2 = 0;

	err2 = init_data(av, &info);
	if (err2 == -1) {
		close(info.serv.fd);
		return print_usage();
	}
	err = server(av, &info);
	if (ac > 1) {
		if (err <= -1 || strcmp("-help", av[1]) == 0) {
			if (err == -1)
				return print_usage();
			return 84;
		}
	}
	return 0;
}
