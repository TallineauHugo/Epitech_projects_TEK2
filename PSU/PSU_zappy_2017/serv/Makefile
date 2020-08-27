##
## EPITECH PROJECT, 2018
##
## File description:
##
##

NAME =	../zappy_server

SRC	=	src/

SRCS	=	$(SRC)hdl_time.c \
		$(SRC)hdl_time_calc.c \
		$(SRC)command_handler.c \
		$(SRC)main.c \
		$(SRC)map.c \
		$(SRC)queue_action_func.c \
		$(SRC)parse_args.c	\
		$(SRC)server.c		\
		$(SRC)serv_env_fcn.c	\
		$(SRC)client_env_fcn.c	\
		$(SRC)list_command.c	\
		$(SRC)init_all_data.c	\
		$(SRC)fill_team.c	\
		$(SRC)get_name_teams.c	\
		$(SRC)player_manager.c	\
		$(SRC)analyze.c		\
		$(SRC)look.c		\
		$(SRC)vision.c		\
		$(SRC)broadcast.c   	\
		$(SRC)check_dead.c	\
		$(SRC)object_string_handler.c\
		$(SRC)set_helper.c	\
		$(SRC)set.c	\
		$(SRC)take.c	\
		$(SRC)take_helper.c	\
		$(SRC)err_args.c    \
		$(SRC)broadcast_complements.c  \
		$(SRC)elevation.c   \
		$(SRC)broadcast_command.c   \
		$(SRC)connect_command.c \
		$(SRC)eject_command.c   \
		$(SRC)fork_command.c    \
		$(SRC)incantation_command.c \
		$(SRC)inventory_command.c   \
		$(SRC)mapitems_commands.c   \
		$(SRC)move_client.c \
		$(SRC)look_command.c    \
		$(SRC)clean_server.c  \
		$(SRC)client_read.c \
		$(SRC)err_port.c    \
		$(SRC)init_all_data2.c  \
		$(SRC)init_client_data.c    \
		$(SRC)parsing_utils.c   \
		$(SRC)queue_complements.c   \
		$(SRC)queue_complements_2.c  \
		$(SRC)server_loop.c \


OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

RM	=	rm -rf

CFLAGS	=	-W -Wall -Wextra -Werror -Iinclude/

LIBS	=	-lm

all:		$(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
