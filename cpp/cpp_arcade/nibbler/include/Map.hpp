//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#pragma once

#include <map>
#include "GraphicElements.hpp"
#include "MapCell.hpp"

#define MAP_SIZE 20
#define FILENAME "map.nibbler"
#define BAD_BORDER "Bad Map: Borders need to be filled with Wall (1),\
maybe the given width and length are wrong !\n"
#define BAD_SNAKE "Bad Map: You need to set one (and only one)\
 snake (3) on the map !\n"
#define BAD_FOOD "Bad Map: no food cell (2) found !\n"
#define MULTIPLE_SNAKE "Bad Map: Multiple definition of snake (3) on map !\n"

class Map
{
public:
	Map();
	~Map();
public:
	void init();
	void display(IGraphicHandler*) const;
	void setValue(t_Vector2i, MapCell);
	t_Vector2i getSize() const;
	t_Vector2i getStartingPos() const;
	MapCell at(t_Vector2i) const;
	bool checkSnake() const;
private:
	void fillMap(std::string, std::size_t);
	bool checkBorder() const;
	bool checkWallTop() const;
	bool checkWallBot() const;
	bool checkWallLeft() const;
	bool checkWallRight() const;

	int _width;
	int _length;
	std::map<int, std::map<int, MapCell> > _map;
};
