/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "proto.h"

bool only_digit(char *str)
{
	size_t i = 0;

	while (isdigit(str[i]) != 0)
		i++;
	if (strlen(str) == i)
		return true;
	return false;
}