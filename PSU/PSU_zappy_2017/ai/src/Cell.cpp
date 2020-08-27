//
// EPITECH PROJECT, 2018
// zappy
// File description:
// cell class implementation
//

#include <iostream>
#include "Cell.hpp"

ai::Cell::Cell()
{
	reset();
}

ai::Cell::~Cell()
{
}

void ai::Cell::reset()
{
	_entities[VILLAGER] = 0;
	_entities[E_FOOD] = 0;
	_entities[E_LINEMATE] = 0;
	std::cout << "bite: " << _entities[E_LINEMATE] << std::endl;
	_entities[E_DERAUMERE] = 0;
	_entities[E_SIBUR] = 0;
	_entities[E_MENDIANE] = 0;
	_entities[E_PHIRAS] = 0;
	_entities[E_THYSTAME] = 0;
}

void ai::Cell::addEntity(ai::Entity type)
{
	auto i = _entities.begin();

        while (i != _entities.end()) {
                if (i->first == type) {
                        this->_entities[type] = this->_entities[type] + 1;
                        break;
                }
                i++;
	}
}

std::size_t ai::Cell::getNbEntity(ai::Entity type)
{
	return this->_entities[type];
}

bool ai::Cell::popRock(Stuff &stuff){
	std::cout << "--- PopRock ----\n";
	if (this->_entities[E_LINEMATE] != 0) {
		stuff = LINEMATE;
		this->_entities[E_LINEMATE] = this->_entities[E_LINEMATE] - 1;
		return true;
	}
	if (this->_entities[E_DERAUMERE] != 0) {
		stuff = DERAUMERE;
		this->_entities[E_DERAUMERE] = this->_entities[E_DERAUMERE] - 1;
		return true;
	}
	if (this->_entities[E_SIBUR] != 0) {
		stuff = SIBUR;
		this->_entities[E_SIBUR] = this->_entities[E_SIBUR] - 1;
		return true;
	}
	if (this->_entities[E_MENDIANE] != 0) {
		stuff = MENDIANE;
		this->_entities[E_MENDIANE] = this->_entities[E_MENDIANE] - 1;
		return true;
	}
	if (this->_entities[E_PHIRAS] != 0) {
		stuff = PHIRAS;
		this->_entities[E_PHIRAS] = this->_entities[E_PHIRAS] - 1;
		return true;
	}
	if (this->_entities[E_THYSTAME] != 0) {
		stuff = THYSTAME;
		this->_entities[E_THYSTAME] = this->_entities[E_THYSTAME] - 1;
		return true;
	}
	return false;
}

void ai::Cell::popFood()
{
	if (this->_entities[E_FOOD] != 0) {
		this->_entities[E_FOOD] -= 1;
	}
}
