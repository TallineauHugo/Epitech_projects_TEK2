//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <string>
#include <fstream>
#include "ArcadeError.hpp"
#include "Map.hpp"

Map::Map() : _width(MAP_SIZE), _length(MAP_SIZE)
{
	init();
}

Map::~Map()
{}

void Map::fillMap(std::string str, std::size_t y)
{
	std::size_t x = 0;

	while (str[x]) {
		switch (str[x]) {
		case '0':
			_map[x][y] = EMPTY;
			break;
		case '1':
			_map[x][y] = WALL;
			break;
		case '2':
			_map[x][y] = FOOD;
			break;
		case '3':
			_map[x][y] = SNAKE;
			break;
		}
		x++;
	}
}

bool Map::checkSnake() const
{
	t_Vector2i tmp;
	bool found = false;

	tmp.x = tmp.y = 0;
	while (tmp.x < _width) {
		while (tmp.y < _length) {
			if (_map.at(tmp.x).at(tmp.y) == SNAKE && found)
				return false;
			else if (_map.at(tmp.x).at(tmp.y) == SNAKE)
				found = true;
			tmp.y += 1;
		}
		tmp.y = 0;
		tmp.x += 1;
	}
	return (found) ? true : false;
}

t_Vector2i Map::getStartingPos() const
{
	t_Vector2i tmp;

	tmp.x = tmp.y = 0;
	while (tmp.x < _width) {
		while (tmp.y < _length) {
			if (_map.at(tmp.x).at(tmp.y) == SNAKE)
				return tmp;
			tmp.y += 1;
		}
		tmp.y = 0;
		tmp.x += 1;
	}
	return tmp;
}

bool Map::checkWallTop() const
{
	int x = 0;
	int y = 0;
	
	while (x < _width) {
		if (_map.at(x).at(y) != WALL)
			return false;
		x++;
	}
	return true;
}

bool Map::checkWallBot() const
{
	int x = 0;
	int y = _length - 1;
	
	while (x < _width) {
		if (_map.at(x).at(y) != WALL)
			return false;
		x++;
	}
	return true;
}

bool Map::checkWallLeft() const
{
	int x = 0;
	int y = 0;
	
	while (y < _length) {
		if (_map.at(x).at(y) != WALL)
			return false;
		y++;
	}
	return true;
}

bool Map::checkWallRight() const
{
	int x = _width - 1;
	int y = 0;
	
	while (y < _length) {
		if (_map.at(x).at(y) != WALL)
			return false;
		y++;
	}
	return true;
}

bool Map::checkBorder() const
{
	if (!checkWallTop() || !checkWallBot() ||
	    !checkWallLeft() || !checkWallRight())
		return false;
	return true;
}

void Map::init()
{
	std::ifstream file(FILENAME);
	std::string buff;
	std::size_t y = 0;

	if (!file.is_open())
		throw ArcadeError("Can't find 'map.nibbler' file !\n");
	file >> _width;
	file >> _length;
	getline(file, buff);
	while (!file.eof()) {
		getline(file, buff);
		fillMap(buff, y);
		y++;
	}
	if (!checkBorder())
		throw ArcadeError(BAD_BORDER);
}

t_Vector2i Map::getSize() const
{
	t_Vector2i v;

	v.x = _width;
	v.y = _length;
	return v;
}

MapCell Map::at(t_Vector2i pos) const
{
	return _map.at(pos.x).at(pos.y);
}

void Map::setValue(t_Vector2i pos, MapCell value)
{
	_map[pos.x][pos.y] = value;
}

void Map::display(IGraphicHandler *lib) const
{
	t_Vector2i pos(0, 0);
	t_Vector2i size(_width, _length);
	t_Vector2i tmp;
	t_Color col(255, 255, 255);

	lib->drawRectangle(pos, size, col);
	col.g = col.b = 0;
	size.x = size.y = 1;
	while (pos.y < _length) {
		while (pos.x < _width) {
			if (_map.at(pos.x).at(pos.y) == WALL)
				lib->drawRectangle(pos, size, col);
			pos.x += 1;
		}
		pos.x = 0;
		pos.y += 1;
	}
}
