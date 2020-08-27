//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <Exception.hpp>
#include <iostream>
#include <cstring>
#include "Player.hpp"

int main(int ac, char **av)
{
	try {
		ai::Parser parser;
		parser.loadArguments(ac, av);
		ai::Player player(parser);
		player.run();
	} catch (ClientError const &e) {
		std::cout << e.what();
		return ((strncmp(e.what(), "dead", 4) == 0) ? 0 : 84);
	}
	return 0;
}
