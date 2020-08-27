/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "hdl_time.h"

/*
** Fonction de remplissage de la structure de temps (pour timer une action)
** En prenant en paramètre une structure fournie par gettimeofday()
*/

void fill_time(hdl_time_t *handleTime, struct timeval *tv)
{
	handleTime->year = ((((tv->tv_sec / 365) / 24) / 60) / 60) + 1970;
	handleTime->day = tv->tv_sec / 60 / 60 / 24 % 365;
	handleTime->hour = tv->tv_sec / 60 / 60 % 24;
	handleTime->min = tv->tv_sec / 60 % 60;
	handleTime->sec = tv->tv_sec % 60;
	handleTime->usec = tv->tv_usec;
}

/*
** Fonction qui permet de retourner une structe de temps contenant la date, heure,
** minute, seconde, et micro-seconde actuel
*/

hdl_time_t *get_current_time(void)
{
	hdl_time_t *handleTime;
	struct timeval tv;

	handleTime = malloc(sizeof(hdl_time_t));
	if (handleTime == NULL)
		return NULL;
	gettimeofday(&tv, NULL);
	fill_time(handleTime, &tv);
	return handleTime;
}

/*
** Fonction qui permet d'actualisé les valeurs d'une structure temps
*/

void update_current_time(hdl_time_t *handleTime)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	fill_time(handleTime, &tv);
}

/*
** Fonction qui permet de copier les valeurs d'une structure et qui retourne
** une nouvelle structure
** Utilisée lors du calcul de la fin d'une action
*/

hdl_time_t *time_struct_cpy(hdl_time_t *handleTime)
{
	hdl_time_t *cpy;

	cpy = malloc(sizeof(hdl_time_t));
	if (cpy == NULL)
		exit(84);
	cpy->year = handleTime->year;
	cpy->day = handleTime->day;
	cpy->hour = handleTime->hour;
	cpy->min = handleTime->min;
	cpy->sec = handleTime->sec;
	cpy->usec = handleTime->usec;
	return cpy;
}
