//
// EPITECH PROJECT, 2018
// zappy
// File description:
// brain
//

#include <Entity.hpp>
#include "Brain.hpp"

ai::Organs::Brain::Brain(ai::Inventory &inv) : _inv(inv), _lvl(1)
{
	std::map<ai::Entity, int> map;

	map[ai::Entity::VILLAGER] = 1;
	map[ai::Entity::E_LINEMATE] = 1;
	map[ai::Entity::E_DERAUMERE] = 0;
	map[ai::Entity::E_SIBUR] = 0;
	map[ai::Entity::E_MENDIANE] = 0;
	map[ai::Entity::E_PHIRAS] = 0;
	map[ai::Entity::E_THYSTAME] = 0;
	_recquired[1] = map;

	map[ai::Entity::VILLAGER] = 2;
	map[ai::Entity::E_LINEMATE] = 1;
	map[ai::Entity::E_DERAUMERE] = 1;
	map[ai::Entity::E_SIBUR] = 1;
	map[ai::Entity::E_MENDIANE] = 0;
	map[ai::Entity::E_PHIRAS] = 0;
	map[ai::Entity::E_THYSTAME] = 0;
	_recquired[2] = map;

	map[ai::Entity::VILLAGER] = 2;
	map[ai::Entity::E_LINEMATE] = 2;
	map[ai::Entity::E_DERAUMERE] = 0;
	map[ai::Entity::E_SIBUR] = 1;
	map[ai::Entity::E_MENDIANE] = 0;
	map[ai::Entity::E_PHIRAS] = 2;
	map[ai::Entity::E_THYSTAME] = 0;
	_recquired[3] = map;

	map[ai::Entity::VILLAGER] = 4;
	map[ai::Entity::E_LINEMATE] = 1;
	map[ai::Entity::E_DERAUMERE] = 1;
	map[ai::Entity::E_SIBUR] = 2;
	map[ai::Entity::E_MENDIANE] = 0;
	map[ai::Entity::E_PHIRAS] = 1;
	map[ai::Entity::E_THYSTAME] = 0;
	_recquired[4] = map;

	map[ai::Entity::VILLAGER] = 4;
	map[ai::Entity::E_LINEMATE] = 1;
	map[ai::Entity::E_DERAUMERE] = 2;
	map[ai::Entity::E_SIBUR] = 1;
	map[ai::Entity::E_MENDIANE] = 3;
	map[ai::Entity::E_PHIRAS] = 0;
	map[ai::Entity::E_THYSTAME] = 0;
	_recquired[5] = map;

	map[ai::Entity::VILLAGER] = 6;
	map[ai::Entity::E_LINEMATE] = 1;
	map[ai::Entity::E_DERAUMERE] = 2;
	map[ai::Entity::E_SIBUR] = 3;
	map[ai::Entity::E_MENDIANE] = 0;
	map[ai::Entity::E_PHIRAS] = 1;
	map[ai::Entity::E_THYSTAME] = 0;
	_recquired[6] = map;

	map[ai::Entity::VILLAGER] = 6;
	map[ai::Entity::E_LINEMATE] = 2;
	map[ai::Entity::E_DERAUMERE] = 2;
	map[ai::Entity::E_SIBUR] = 2;
	map[ai::Entity::E_MENDIANE] = 2;
	map[ai::Entity::E_PHIRAS] = 2;
	map[ai::Entity::E_THYSTAME] = 1;
	_recquired[7] = map;

	initEntityToStuff();
}

ai::Organs::Brain::~Brain()
{
}

void ai::Organs::Brain::initEntityToStuff()
{
	this->_eToStuff[E_FOOD] = FOOD;
	this->_eToStuff[E_LINEMATE] = LINEMATE;
	this->_eToStuff[E_DERAUMERE] = DERAUMERE;
	this->_eToStuff[E_SIBUR] = SIBUR;
	this->_eToStuff[E_MENDIANE] = MENDIANE;
	this->_eToStuff[E_PHIRAS] = PHIRAS;
	this->_eToStuff[E_THYSTAME] = THYSTAME;
}

std::map<ai::Entity, int> ai::Organs::Brain::getRecquiredItemsForLvlUp()
{
	return _recquired[_lvl];
}
#include <iostream>
std::map<ai::Entity, int> ai::Organs::Brain::getRecquiredItems()
{
	std::map<ai::Entity, int> map;

	if (_lvl < 8)
		map = _recquired[_lvl];
	map[E_FOOD] = (_lvl < 8) ?
		map[E_FOOD] - _inv.getNbStuff(ai::Stuff::FOOD) : -3;
	map[E_MENDIANE] = (_lvl < 8) ?
		map[E_MENDIANE] - _inv.getNbStuff(ai::Stuff::MENDIANE) : -3;
	map[E_SIBUR] = (_lvl < 8) ?
		map[E_SIBUR] - _inv.getNbStuff(ai::Stuff::SIBUR) : -3;
	map[E_THYSTAME] = (_lvl < 8) ?
		map[E_THYSTAME] - _inv.getNbStuff(ai::Stuff::THYSTAME) : -3;
	map[E_LINEMATE] = (_lvl < 8) ?
		map[E_LINEMATE] - _inv.getNbStuff(ai::Stuff::LINEMATE) : -3;
	map[E_DERAUMERE] = (_lvl < 8) ?
		map[E_DERAUMERE] - _inv.getNbStuff(ai::Stuff::DERAUMERE) : -3;
	map[E_PHIRAS] = (_lvl < 8) ?
		map[E_PHIRAS] - _inv.getNbStuff(ai::Stuff::PHIRAS) : -3;
	return map;
}

void ai::Organs::Brain::upgrade()
{
	_lvl += 1;
}

bool ai::Organs::Brain::canElevate()
{
	std::map<Entity, int> map = getRecquiredItems();

	return (map[E_LINEMATE] <= 0 &&
		map[E_DERAUMERE] <= 0 &&
		map[E_SIBUR] <= 0 &&
		map[E_MENDIANE] <= 0 &&
		map[E_PHIRAS] <= 0 &&
		map[E_THYSTAME] <= 0);
}

ai::Stuff ai::Organs::Brain::convertEntityToStuff(ai::Entity entity)
{
	return this->_eToStuff[entity];
}
