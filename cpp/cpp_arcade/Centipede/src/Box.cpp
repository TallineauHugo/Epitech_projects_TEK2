//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Box
//

#include "Box.hpp"

Box::Box(t_Vector2i pos) : Object(5, pos)
{
}

Box::~Box()
{
}

void Box::display(IGraphicHandler *lib)
{
	lib->drawRectangle(_pos, t_Vector2i(CENTIPEDE_SIZE_X, CENTIPEDE_SIZE_Y), t_Color(255, 0, 255));
}
