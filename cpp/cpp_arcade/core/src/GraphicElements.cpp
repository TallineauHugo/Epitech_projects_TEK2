//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Graphic Elements
//

#include "GraphicElements.hpp"

s_Vector2i::s_Vector2i(int x, int y) : x(x), y(y)
{}

bool s_Vector2i::operator==(s_Vector2i a)
{
	if (this->x == a.x && this->y == a.y)
		return true;
	return false;
}

s_Color::s_Color(int r, int g, int b) : r(r), g(g), b(b)
{
	a = 255;	
}
