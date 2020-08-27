//
// EPITECH PROJECT, 2018
// nibbler
// File description:
// cell
//

#include "Cell.hpp"

Cell::Cell(s_Vector2i pos) : _pos(pos)
{
	_nextPos.x = -1;
	_nextPos.y = -1;	
	_oldPos.x = -1;
	_oldPos.y = -1;
	_col.r = 0;
	_col.g = 255;
	_col.b = 0;
	_col.a = 255;
}

Cell::~Cell()
{}

void Cell::display(IGraphicHandler *lib) const
{
	s_Vector2i size;

	size.x = size.y = 1;
	lib->drawRectangle(_pos, size, _col);
}
