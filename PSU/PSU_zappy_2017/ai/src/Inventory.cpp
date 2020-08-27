//
// EPITECH PROJECT, 2018
// zappy
// File description:
// inventory
//

#include <iostream>
#include "Inventory.hpp"

ai::Inventory::Inventory(Parser &parser) : _parser(parser)
{
	initInventory();
	initStuffStr();
}

ai::Inventory::~Inventory()
{
}

void ai::Inventory::initStuffStr()
{
	_eStr[FOOD] = "food";
	_eStr[LINEMATE] = "linemate";
	_eStr[DERAUMERE] = "deraumere";
	_eStr[SIBUR] = "sibur";
	_eStr[MENDIANE] = "mendiane";
	_eStr[PHIRAS] = "phiras";
	_eStr[THYSTAME] = "thystame";
}

void ai::Inventory::initInventory()
{
	_inventory[FOOD] = 10;
	_inventory[LINEMATE] = 0;
	_inventory[DERAUMERE] = 0;
	_inventory[SIBUR] = 0;
	_inventory[MENDIANE] = 0;
	_inventory[PHIRAS] = 0;
	_inventory[THYSTAME] = 0;

	_convertString[FOOD_STRING] = FOOD;
	_convertString[LINEMATE_STRING] = LINEMATE;
	_convertString[DERAUMERE_STRING] = DERAUMERE;
	_convertString[SIBUR_STRING] = SIBUR;
	_convertString[MENDIANE_STRING] = MENDIANE;
	_convertString[PHIRAS_STRING] = PHIRAS;
	_convertString[THYSTAME_STRING] = THYSTAME;
}

void ai::Inventory::addStuff(Stuff type, std::size_t nb)
{
	_inventory[type] += nb;
}

void ai::Inventory::removeStuff(Stuff type, std::size_t nb)
{
	if (_inventory[type] >= nb)
		_inventory[type] -= nb;
	else
		_inventory[type] = 0;
}

std::size_t ai::Inventory::getNbStuff(Stuff type)
{
	return _inventory[type];
}

void ai::Inventory::updateRessourceByToken(std::string token)
{
	std::list<std::string> ressource = _parser.getToken(token, " ");
	std::list<std::string>::iterator i = ressource.begin();
	std::string type;
	std::string amount;
	int nb;

	if (ressource.size() != 2)
		return;
	type = (*i);
	i++;
	amount = (*i);
	if (amount.find_first_of("0123456789") == std::string::npos)
		return;
	nb = std::stoi(amount);
	if (nb > 0 && _convertString.find(type) != _convertString.end())
		setNbStuff(_convertString[type], (std::size_t)nb);
}

void ai::Inventory::updateInventory(std::string &rawInventory)
{
	std::string token;
	std::string str(rawInventory);
	std::list<std::string> tokens;
	std::list<std::string>::iterator i;

	if (!(rawInventory.compare(0, 2, "ko") || rawInventory.compare(0, 2, "ok")))
		return;
	_parser.replace(str, "[", "");
	_parser.replace(str, "]", "");
	_parser.epurestr(str);
	tokens = _parser.getToken(str, ",\n");
	i = tokens.begin();
	while (i != tokens.end()) {
		updateRessourceByToken((*i));
		i++;
	}
	this->dump();
}

void ai::Inventory::dump()
{
	std::cout << "Inventory :" << std::endl;
	std::map<Stuff, std::size_t>::iterator it = _inventory.begin();

	while (it != _inventory.end()) {
		std::cout << _eStr[it->first] << " : " << it->second << std::endl;
		it++;
	}
}

void ai::Inventory::setNbStuff(ai::Stuff type, std::size_t nb)
{
	_inventory[type] = nb;
}
