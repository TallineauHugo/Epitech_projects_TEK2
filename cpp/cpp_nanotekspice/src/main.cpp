//
// EPITECH PROJECT, 2018
// nano
// File description:
// main
//

#include <iostream>
#include <stdlib.h>
#include "Nanotekspice.hpp"

int main(int ac, char **av)
{
	Nanotekspice *nano = nullptr;

	if (ac < 2) {
		std::cout << "Usage: " << av[0];
		std::cout << " file.nts [input=value]" << std::endl;
		return 84;
	}
	try {
		nano = new Nanotekspice(ac, av);
		nano->launchShell();
		delete nano;

	} catch (NtsError const& e) {
		std::cout << e.what() << std::endl;
		delete nano;
		return 84;
	}
	return 0;
}
