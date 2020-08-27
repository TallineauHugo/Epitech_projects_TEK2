/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#pragma once

#include <stdbool.h>
#include "struct.h"

typedef struct calc_s {
	int dec;
	int x;
	int y;
} calc_t;

char *my_realloc(char *str, const char c[]);

char *get_loot(bag_t *bag, char *msg);

char *analyse_verti(map_t *map, calc_t tool, char *msg, bool sens);

char *analyse_hori(map_t *map, calc_t tool, char *msg, bool sens);

char *look(map_t *map, client_t *player);
