##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CC	=	g++

LDL	=	-ldl

RM	=	rm -f

SRC	=	src/

SRCS	=	$(SRC)GraphicElements.cpp \
		$(SRC)DLLoader.cpp \
		$(SRC)Menu.cpp \
		$(SRC)main.cpp

OBJ	=	$(SRCS:.cpp=.o)

NAME	=	../arcade

CXXFLAGS	+=	-Wall -Wextra -I./include -std=c++11

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CXXFLAGS) -o $(NAME) $(LDL)

clean:
	$(RM) $(OBJ)
	$(RM) $(SRCS:.cpp=.cpp~)
	$(RM) $(SRCS:.cpp=.cpp#)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
