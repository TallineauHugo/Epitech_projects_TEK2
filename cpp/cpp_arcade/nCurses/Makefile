##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC	=	g++

FPIC	=	-fPIC

SHARED	=	-shared

NCURSES	=	-lncurses

RM	=	rm -f

SRC	=	src/

SRCS	=	$(SRC)GraphicElements.cpp \
		$(SRC)NcursesGraphicHandler.cpp \
		$(SRC)Window.cpp

NAME	=	../lib/lib_arcade_ncurses.so

CXXFLAGS	+=	-Wall -Wextra -Werror -I./include -std=c++11

all:	$(NAME)

$(NAME):
	$(CC) $(FPIC) $(SHARED) $(SRCS) $(CXXFLAGS) -o $(NAME) $(NCURSES)

clean:

	$(RM) $(SRCS:.cpp=.cpp~)
	$(RM) $(SRCS:.cpp=.cpp#)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
