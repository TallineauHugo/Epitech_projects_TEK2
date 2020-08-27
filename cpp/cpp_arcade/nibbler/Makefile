##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC	=	g++

FPIC	=	-fPIC

SHARED	=	-shared

RM	=	rm -f

SRC	=	src/

SRCS	=	$(SRC)Cell.cpp \
		$(SRC)NibblerGameHandler.cpp \
		$(SRC)Food.cpp \
		$(SRC)GraphicElements.cpp \
		$(SRC)Head.cpp \
		$(SRC)Map.cpp \
		$(SRC)Snake.cpp \
		$(SRC)TemporaryFood.cpp

NAME	=	../games/lib_arcade_nibbler.so

CXXFLAGS	+=	-Wall -Wextra -Werror -I./include -std=c++11

all:	$(NAME)

$(NAME):
	$(CC) $(FPIC) $(SHARED) $(SRCS) $(CXXFLAGS) -o $(NAME)

clean:

	$(RM) $(SRCS:.cpp=.cpp~)
	$(RM) $(SRCS:.cpp=.cpp#)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
