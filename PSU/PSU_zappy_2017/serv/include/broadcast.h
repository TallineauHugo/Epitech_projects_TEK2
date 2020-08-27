/*
** EPITECH PROJECT, 2018
** myirc
** File description:
** server/broadcast
*/

#ifndef BROADCAST_H_
# define BROADCAST_H_

# include <memory.h>
# include <math.h>
# include <stdio.h>
# include "struct.h"

# define        M_PI_8 (M_PI / 8)

typedef enum e_sound {
	S_NONE = 0,
	S_NORTH = 1,
	S_NORTH_WEST = 2,
	S_WEST = 3,
	S_SOUTH_WEST = 4,
	S_SOUTH = 5,
	S_SOUTH_EAST = 6,
	S_EAST = 7,
	S_NORTH_EAST = 8
} sounddir_t;

typedef struct s_vector {
	size_t x;
	size_t y;
} vector_t;

typedef struct s_dirvariation {
	double min;
	double max;
	sounddir_t sound;
} dirvariation_t;

bool broadcast(info_t *, client_t *, char *);

char *create_broadcast(int dir, char *cmd);

#endif /* !BROADCAST_H_ */
