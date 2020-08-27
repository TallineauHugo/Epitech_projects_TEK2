//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede object cpp
//

#include "Object.hpp"
#include "GraphicElements.hpp"

Object::Object(int life, t_Vector2i pos) : _life(life), _pos(pos)
{
}

void Object::display(IGraphicHandler *graph)
{
	int x = _pos.x;
	int y = _pos.y;

	while (y < _pos.y + PLAYER_SIZE_Y) {
		x = _pos.x;
		while (x < _pos.x + PLAYER_SIZE_X) {
			graph->putPixel(t_Vector2i(x, y), t_Color(255, 0, 0));
			x++;
		}
		y++;
	}
}

t_Vector2i &Object::getPos()
{
	return _pos;
}

void Object::setPos(t_Vector2i pos)
{
	_pos = pos;
}

int Object::getLife()
{
	return _life;
}

void Object::loseLife()
{
	_life--;
}

void Object::setLife(int life)
{
	_life = life;
}
