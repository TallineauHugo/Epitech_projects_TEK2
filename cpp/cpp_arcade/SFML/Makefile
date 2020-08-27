##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC	=	g++

FPIC	=	-fPIC

SHARED	=	-shared

SFML	=	-lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window 

RM	=	rm -f

SRC	=	src/

CORESRC	=	../core/src/

SRCS	=	$(CORESRC)GraphicElements.cpp \
		$(SRC)SFMLGraphicHandler.cpp \

NAME	=	../lib/lib_arcade_sfml.so

CXXFLAGS	+=	-Wall -Wextra -Werror -I./include -I./../core/include/ -std=c++11

all:	$(NAME)

$(NAME):
	$(CC) $(FPIC) $(SHARED) $(SRCS) $(CXXFLAGS) -o $(NAME) $(NCURSES) $(SFML)

clean:

	$(RM) $(SRCS:.cpp=.cpp~)
	$(RM) $(SRCS:.cpp=.cpp#)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
