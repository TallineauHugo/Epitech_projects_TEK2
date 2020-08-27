//
// EPITECH PROJECT, 2018
// zappy
// File description:
// inventory class declaration
//

#pragma once

#include <map>
#include "Stuff.hpp"
#include "Parser.hpp"

#define FOOD_STRING "food"
#define LINEMATE_STRING "linemate"
#define DERAUMERE_STRING "deraumere"
#define SIBUR_STRING "sibur"
#define MENDIANE_STRING "mendiane"
#define PHIRAS_STRING "phiras"
#define THYSTAME_STRING "thystame"

namespace ai
{
	class Inventory
	{
	public:
		Inventory(Parser &parser);
		~Inventory();
	public:
		void updateInventory(std::string &rawInventory);
		void addStuff(Stuff type, std::size_t nb);
		void removeStuff(Stuff type, std::size_t nb);

		std::size_t getNbStuff(Stuff type);
	private:
		void setNbStuff(Stuff type, std::size_t nb);
		void initInventory();
		void updateRessourceByToken(std::string token);
		void initStuffStr();
		void dump();
	private:
		Parser &_parser;
		std::map<std::string, Stuff> _convertString;
		std::map<Stuff, std::size_t> _inventory;
		std::map<ai::Stuff, std::string> _eStr;
	};
}