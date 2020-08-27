//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "TemporaryFood.hpp"

TemporaryFood::TemporaryFood()
{
	_col.r = 255;
	_col.g = 255;
	_col.b = 0;
	_col.a = 255;
}

TemporaryFood::~TemporaryFood()
{}

void TemporaryFood::display(IGraphicHandler *lib) const
{
	std::list<std::pair<t_Vector2i, int>>::const_iterator t =
		_tmpFoodList.begin();
	t_Vector2i size;

	size.x = size.y = 1;
	while (t != _tmpFoodList.end()) {
		lib->drawRectangle(t->first, size, _col);
		t++;
	}
}

void TemporaryFood::handleTemporaryFood()
{
	std::list<std::pair<t_Vector2i, int>>::iterator t =
		_tmpFoodList.begin();
	
	while (t != _tmpFoodList.end()) {
		t->second -= 1;
		if (t->second == 0)
			t = removeFood(t->first);
		else
			t++;
	}
}

void TemporaryFood::addFood(t_Vector2i pos)
{
	_tmpFoodList.push_back(std::make_pair(pos, 100));
}

std::list<std::pair<t_Vector2i, int>>::iterator
	TemporaryFood::removeFood(t_Vector2i pos)
{
	std::list<std::pair<t_Vector2i, int>>::iterator t =
		_tmpFoodList.begin();

	while (t != _tmpFoodList.end()) {
		if (t->first.x == pos.x && t->first.y == pos.y) {
			t = _tmpFoodList.erase(t);
			break;			                
		}
		t++;
	}
	return t;
}
