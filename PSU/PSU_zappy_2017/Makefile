##
## EPITECH PROJECT, 2018
##
## File description:
##
##

all:	main

main: zappy

zappy:
	make -C ./serv/
	make -C ./ai/

clean:
	make -C ./serv/ clean
	make -C ./ai/ clean

fclean:
	make -C ./serv/ fclean
	make -C ./ai/ fclean

re: fclean all

.PHONY: all main clean fclean re
