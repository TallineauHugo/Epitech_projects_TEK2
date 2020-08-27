//
// EPITECH PROJECT, 2018
// food
// File description:
// arcade
//

#include "Food.hpp"

Food::Food()
{
	_col.r = 255;
	_col.g = 0;
	_col.b = 255;
	_col.a = 255;
}

Food::~Food()
{}

void Food::display(IGraphicHandler *lib) const
{
	std::list<t_Vector2i>::const_iterator t = _foodList.begin();
	t_Vector2i size;

	size.x = size.y = 1;
	while (t != _foodList.end()) {
		lib->drawRectangle((*t), size, _col);
		t++;
	}
}

void Food::addFood(t_Vector2i pos)
{
	_foodList.push_back(pos);
}

void Food::removeFood(t_Vector2i pos)
{
	std::list<t_Vector2i>::iterator t = _foodList.begin();

	while (t != _foodList.end()) {
		if (t->x == pos.x && t->y == pos.y) {
			t = _foodList.erase(t);
			break;
		}
		t++;		
	}
}
