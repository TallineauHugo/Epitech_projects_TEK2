//
// EPITECH PROJECT, 2018
// zappy
// File description:
// core
//

#pragma once

#include "Player.hpp"
#include "Parser.hpp"

namespace ai
{
	class Core
	{
	public:
		Core();
		~Core();
	private:
		std::string _teamName;
		Parser &_parser;
		Player &_player;
	};
}
