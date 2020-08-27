##
## EPITECH PROJECT, 2018
## zappy
## File description:
## Makefile
##

CC		=	g++

RM		=	rm -f

SRC		=	src/

SRCS		=	$(SRC)main.cpp			\
			$(SRC)Cell.cpp			\
			$(SRC)FoV.cpp			\
			$(SRC)Eyes.cpp			\
			$(SRC)Inventory.cpp		\
			$(SRC)Parser.cpp		\
			$(SRC)Request.cpp		\
			$(SRC)RequestFactory.cpp	\
			$(SRC)Stomach.cpp 		\
			$(SRC)Exception.cpp		\
			$(SRC)Brain.cpp			\
			$(SRC)Player.cpp		\
			$(SRC)Mouth.cpp			\
			$(SRC)SignalHandler.cpp \
			$(SRC)CommandManager.cpp \
			$(SRC)Queue.cpp

TEST		=	tests/

TEST_SRCS	=	

OBJ		=	$(SRCS:.cpp=.o)

OBJ_TEST	=	$(TEST_SRCS:.cpp=.o)

NAME		=	../zappy_ai

NAME_TEST	=	criterion

CXXFLAGS	+=	-Wall -Wextra -Werror -I./include -std=c++14 -g

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(SRCS:.cpp=.cpp~)
	$(RM) $(SRCS:.cpp=.cpp#)
	$(RM) $(OBJ_TEST)
	$(RM) $(SRCS:.cpp=.cpp~)
	$(RM) $(SRCS:.cpp=.cpp#)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_TEST)

re: fclean all

c: re
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)

tests_run:	re $(OBJ_TEST)
		$(CC) $(OBJ_TEST) -o $(NAME_TEST) -lcriterion -coverage
		./criterion --verbose

.PHONY: all clean fclean re
