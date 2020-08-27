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

CORESRC	=	../core/src/

SRCS	=	$(CORESRC)GraphicElements.cpp \
		$(SRC)Player.cpp \
		$(SRC)SpeedRacerGameHandler.cpp

NAME	=	../games/lib_arcade_speedracer.so

CXXFLAGS	+=	-Wall -Wextra -Werror -I./include -I../core/include/ -std=c++11

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
