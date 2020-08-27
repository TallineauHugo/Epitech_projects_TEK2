//
// EPITECH PROJECT, 2018
// arcade
// File description:
// main
//

#include "DLLoader.hpp"
#include "ArcadeError.hpp"

int	main(int ac, char **av)
{
	DLLoader	loader;

	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " [graphic_lib]" << std::endl;
		return 84;
	}
	try {
		loader.initListGame();
		loader.initListGraph();
		loader.initGraph(av[1]);
		loader.initGame();
		loader.play();
		loader.close();
	}
	catch (const ArcadeError& e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
	return 0;
}
