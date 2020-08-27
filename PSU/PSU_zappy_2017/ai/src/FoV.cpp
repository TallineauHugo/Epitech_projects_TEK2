//
// EPITECH PROJECT, 2018
// zappy
// File description:
// field of view class implementation
//

#include <iostream>
#include <sstream>

#include "FoV.hpp"

ai::FoV::FoV(Parser &parser) : _level(1), _parser(parser)
{
	_cells[0] = new Cell;
	_cells[1] = new Cell;
	_cells[2] = new Cell;
	_cells[3] = new Cell;
	_middles[0] = 0;
	_middles[1] = 2;
}

ai::FoV::~FoV()
{
	auto it = this->_cells.begin();

	while (it != this->_cells.end()) {
		delete this->_cells[it->first];
		it++;
	}
	it = this->_foods.begin();
	while (it != this->_foods.end()) {
		delete this->_foods[it->first];
		it++;
	}
	it = this->_stuffs.begin();
	while (it != this->_stuffs.end()) {
		delete this->_stuffs[it->first];
		it++;
	}
}

short ai::FoV::getMiddle(short line) const
{
	return line == 0 ? 0 : this->getMiddle(line - 1) + 2 * line;
}

std::pair<short, short> ai::FoV::getLeft(short line)
{
	short a = this->_middles[line] - line;
	short b = line == 0 ? 0 : this->_middles[line] - 1;
	std::pair<short, short> interval = std::make_pair(a, b);

	return interval;
}

std::pair<short, short> ai::FoV::getRight(short line)
{
	short a = line == 0 ? 0 : this->_middles[line] + 1;
	short b = this->_middles[line] + line;
	std::pair<short, short> interval = std::make_pair(a, b);

	return interval;
}

void ai::FoV::initLine(short nb)
{
	std::size_t start = getLeft(nb).first;
	std::size_t end = getRight(nb).second;

	while (start != end + 1) {
		this->_cells[start] = new Cell;
		start++;
	}
}

void ai::FoV::initEntitiesStr()
{
	this->_eStr[PlYR_STR] = VILLAGER;
	this->_eStr[FOOD_STR] = E_FOOD;
	this->_eStr[LINE_STR] = E_LINEMATE;
	this->_eStr[DER_STR] = E_DERAUMERE;
	this->_eStr[SIB_STR] = E_SIBUR;
	this->_eStr[MEND_STR] = E_MENDIANE;
	this->_eStr[PHIR_STR] = E_PHIRAS;
	this->_eStr[THYS_STR] = E_THYSTAME;
}

void ai::FoV::upgrade()
{
	this->_level++;
	initLine(this->_level);
	_middles[this->_level] = this->getMiddle(this->_level);
}

std::map<short, ai::Cell *> ai::FoV::getVision() const
{
	return this->_cells;
}

void ai::FoV::setVision(std::string rawView)
{
	std::list<std::string> tokens;
	std::list<std::string>::iterator it;
	std::list<std::string> subTokens;
	//std::list<std::string>::iterator sub;
	//Cell *cell;
	short i = 0;

	this->_foods.clear();
	this->_stuffs.clear();
	this->_parser.replace(rawView, COMMAND_START, EMPTY);
	this->_parser.replace(rawView, COMMAND_END, EMPTY);
	this->_parser.epurestr(rawView);
	tokens = this->_parser.getToken(rawView, CELL_DELIM);
	it = tokens.begin();
	while (it != tokens.end()) {
		//cell = this->_cells[i];
		//subTokens = this->_parser.getToken(*it, OBJ_DELIM);
		this->processCell(i, *it);
		/*
		sub = subTokens.begin();
		while (sub != subTokens.end()) {
			if (_eStr.find(*sub) != _eStr.end())
				this->split(i, *sub);
				cell->addEntity(this->_eStr[*sub]);
			sub++;
		}
		 */
		it++;
		i++;
	}
}

void ai::FoV::processCell(short cell, std::string content)
{
	std::istringstream iss(content);
	std::string word;

	this->_foods[cell] = new Cell();
	this->_stuffs[cell] = new Cell();
	while (iss >> word) {
		if (_eStr.find(word) != _eStr.end()) {
			this->_cells[cell]->addEntity(this->_eStr[word]);
			if (word == "food")
				this->_foods[cell]->addEntity(E_FOOD);
			else
				this->_stuffs[cell]->addEntity(
					this->_eStr[word]);
		}
	}
}

std::map<short, ai::Cell *> ai::FoV::getFoods()
{
	return this->_foods;
}

std::map<short, ai::Cell *> ai::FoV::getStuffs()
{
	return this->_stuffs;
}

void ai::FoV::reset()
{
	auto it = this->_cells.begin();

	while (it != this->_cells.end()) {
		it->second->reset();
		it++;
	}
}

void ai::FoV::dump()
{
	auto it = this->_cells.begin();
	Cell *cell;

	std::cout << "Vision :" << std::endl;
	while (it != this->_cells.end()) {
		cell = it->second;
		DUMP_CELL_ID(it->first);
		DUMP_ENTITY(cell->getNbEntity(VILLAGER), PLYR_DUMP);
		DUMP_ENTITY(cell->getNbEntity(E_FOOD), FOOD_DUMP);
		DUMP_ENTITY(cell->getNbEntity(E_LINEMATE), LINE_DUMP);
		DUMP_ENTITY(cell->getNbEntity(E_DERAUMERE), DER_DUMP);
		DUMP_ENTITY(cell->getNbEntity(E_SIBUR), SIB_DUMP);
		DUMP_ENTITY(cell->getNbEntity(E_MENDIANE), MEND_DUMP);
		DUMP_ENTITY(cell->getNbEntity(E_PHIRAS), PHIR_DUMP);
		DUMP_ENTITY(cell->getNbEntity(E_PHIRAS), THYS_DUMP);
		it++;
		if (it != this->_cells.end())
			std::cout << SEP_DUMP << std::endl;
	}
}

std::pair<short, short> ai::FoV::getPath(short cell)
{
	short up = 0;
	short horiz = 0;

	while (this->_middles.find(up) != this->_middles.end() && this->_middles[up] < cell)
		up++;

	std::pair<short, short> left(this->getLeft(up));

	if (this->_middles[up] == cell)
		return std::make_pair(up, horiz);
	else if (!(left.first <= cell && left.second >= cell))
		up--;
	horiz = cell - this->_middles[up];
	return std::make_pair(up, horiz);
}

std::pair<short, short> ai::FoV::getPathFromTo(short from, short to)
{
	std::pair<short, short> fromPath = this->getPath(from);
	std::pair<short, short> toPath = this->getPath(to);
	short x = toPath.first - fromPath.first;
	short y = toPath.second - fromPath.second;

	return std::make_pair(x, y);
}

short ai::FoV::getNearestItem(ai::Entity type)
{
	auto i = _cells.begin();

	while (i != _cells.end()) {
		if (i->second->getNbEntity(type) > 0)
			return i->first;
		i++;
	}
	return -1;
}

std::size_t ai::FoV::getNbVillager()
{
	return this->_cells[0]->getNbEntity(VILLAGER);
}

bool ai::FoV::popRock(ai::Stuff &stuff, short cell)
{
	return this->_cells[cell]->popRock(stuff);
}
