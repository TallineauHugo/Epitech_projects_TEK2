##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/

SRCS	=	$(SRC)main.c \
		$(SRC)parse_arguments.c \
		$(SRC)setup.c \
		$(SRC)simulation.c

OBJ	=	$(SRCS:.c=.o)

NAME	=	philo

CFLAGS	+=	-Wall -Wextra -Werror -I./include

LDFLAGS	+=	-L./lib -lriceferee -lpthread

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(SRCS:.c=.c~)
	$(RM) $(SRCS:.c=.c#)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
