##
## EPITECH PROJECT, 2018
##
## File description:
##
##

CC	=	g++

RM	=	rm -f

SRC	=	src/

COMPONENT	=	$(SRC)component/

CHIPSET	=	$(COMPONENT)chipset/

SRCS	=	$(SRC)main.cpp \
		$(SRC)Exception.cpp \
		$(SRC)Nanotekspice.cpp \
		$(COMPONENT)Clock.cpp \
		$(COMPONENT)Component.cpp \
		$(COMPONENT)False.cpp \
		$(COMPONENT)Input.cpp \
		$(COMPONENT)Output.cpp \
		$(COMPONENT)True.cpp \
		$(COMPONENT)ComponentFactory.cpp \
		$(CHIPSET)C4071.cpp \
		$(CHIPSET)C4001.cpp \
		$(CHIPSET)C4011.cpp \
		$(CHIPSET)C4030.cpp \
		$(CHIPSET)C4081.cpp \
		$(CHIPSET)C4008.cpp \
		$(CHIPSET)C4069.cpp \
		$(CHIPSET)C4040.cpp \
		$(CHIPSET)C4013.cpp \
		$(CHIPSET)FlipFlop.cpp

OBJ	=	$(SRCS:.cpp=.o)

NAME	=	nanotekspice

CXXFLAGS  +=	-Wall -Wextra -Werror -I./include -I./include/chipset -std=c++11

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(SRCS:.cpp=.cpp~)
	$(RM) $(SRCS:.cpp=.cpp#)

fclean: clean
	$(RM) $(NAME)

re:	fclean  all

.PHONY: all clean fclean re
