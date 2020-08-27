//
// EPITECH PROJECT, 2018
// zappy
// File description:
// eyes class implementation
//

#include "Eyes.hpp"

ai::Organs::Eyes::Eyes(Parser &parser): _fov(parser)
{
	_fov.initEntitiesStr();
}

void ai::Organs::Eyes::look(std::string rawView)
{
	this->_fov.reset();
	this->_fov.setVision(rawView);
	this->_fov.dump();
}

void ai::Organs::Eyes::upgrade()
{
	this->_fov.upgrade();
}

std::pair<short, short> ai::Organs::Eyes::getPath(short cell)
{
	return this->_fov.getPath(cell);
}

std::pair<short, short> ai::Organs::Eyes::getPathFromTo(short from, short to)
{
	return this->_fov.getPathFromTo(from, to);
}

short ai::Organs::Eyes::getNearestItem(ai::Entity type)
{
	return this->_fov.getNearestItem(type);
}

std::size_t ai::Organs::Eyes::getNbVillager()
{
	return this->_fov.getNbVillager();
}

std::map<short, ai::Cell*> ai::Organs::Eyes::getFoods()
{
	return this->_fov.getFoods();
}

std::map<short, ai::Cell*> ai::Organs::Eyes::getStuffs()
{
	return this->_fov.getStuffs();
}

bool ai::Organs::Eyes::popRock(ai::Stuff &stuff, short cell)
{
	return this->_fov.popRock(stuff, cell);
}
