//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Bullet
//

#include "Bullet.hpp"

Bullet::Bullet() : Object(1, t_Vector2i(-1, -1))
{
}

Bullet::~Bullet()
{
}

void Bullet::moveForward()
{
	_pos.y -= 2;
	if (_pos.y < 0) {
		_shot = false;
	}
		
}

void Bullet::detectHit(CentipedeGameHandler& game)
{
	if (_shot != false)
		game.detectTarget(*this);
}

bool Bullet::getShot()
{
	return _shot;
}

void Bullet::setShot(bool state)
{
	_shot = state;
}

void Bullet::display(IGraphicHandler *lib)
{
	lib->drawRectangle(_pos, t_Vector2i(BULLET_SIZE_X, BULLET_SIZE_Y), t_Color());
}
