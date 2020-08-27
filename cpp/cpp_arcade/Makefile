all:	graphicals games core

games:
	make -C ./Centipede/
	make -C ./nibbler/
	make -C ./Speedracer/

graphicals:
	make -C ./nCurses/

core:
	make -C ./core/

clean:
	make -C ./Centipede/ clean
	make -C ./nibbler/ clean
	make -C ./Speedracer/ clean
	make -C ./nCurses/ clean
	make -C ./SFML/ clean
	make -C ./core/ clean

fclean:
	make -C ./Centipede/ fclean
	make -C ./nibbler/ fclean
	make -C ./Speedracer/ fclean
	make -C ./nCurses/ fclean
	make -C ./SFML/ fclean
	make -C ./core/ fclean

re: fclean all

.PHONY: all games graphicals core clean fclean re
