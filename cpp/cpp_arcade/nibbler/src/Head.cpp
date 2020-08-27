//
// EPITECH PROJECT, 2018
// head
// File description:
// arcade
//

#include "Head.hpp"

Head::Head(t_Vector2i pos) : Cell(pos)
{
	_col.b = 255;
	_nextPos.y = _pos.y - 1;
	_nextPos.x = _pos.x;
}

Head::~Head()
{}

void Head::display(IGraphicHandler *lib) const
{
	t_Vector2i size;

	size.x = size.y = 1;
	lib->drawRectangle(_pos, size, _col);
}
