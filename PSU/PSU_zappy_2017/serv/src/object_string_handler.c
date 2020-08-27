/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Fonction qui permet de récupérer l'objet en paramètre avec une action
** comme Set ou Take
*/

char *get_object(char *action)
{
	char *str;
	int i, j = 0;

	str = malloc(sizeof(char) * strlen(action));
	for (i = 0; action[i] != '\0' && action[i] != ' '; i++);
	for (i = i + 1; action[i] != '\0'; i++) {
		if (action[i] == ' ')
			break;
		str[j++] = action[i];
	}
	str[j] = '\0';
	return str;
}
