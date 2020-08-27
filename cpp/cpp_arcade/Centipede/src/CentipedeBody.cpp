//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Body
//

#include "CentipedeBody.hpp"
#include <stdlib.h>

CentipedeBody::CentipedeBody(t_Vector2i pos) : Object(1, pos)
{
	nextPos = pos;
	_dir = RIGHT;
}

CentipedeBody::~CentipedeBody()
{
}

void CentipedeBody::setNextPos(t_Vector2i pos)
{
	nextPos = pos;
}

t_Vector2i CentipedeBody::getNextPos()
{
	return nextPos;
}

void CentipedeBody::setDown(int pos)
{
	down = pos;
}

void CentipedeBody::move(CentipedeGameHandler& game)
{
	if (_pos.y < 0) {
		_pos.y++;
		return;
	}
	move2(game);
}

void CentipedeBody::move2(CentipedeGameHandler& game)
{
	t_Vector2i tmp;
	int i;

	tmp.x = _pos.x;
	tmp.y = _pos.y;
	if (down-- > 0)
		_pos.y++;
	else if (_dir == LEFT)
		_pos.x--;
	else
		_pos.x++;
	i = game.check_boxes(_pos, t_Vector2i(CENTIPEDE_SIZE_X,
					      CENTIPEDE_SIZE_Y));
	if (i) {
		_pos = tmp;
		_dir = (Direction)(((int)_dir + 2) % 4);
		down = CENTIPEDE_SIZE_Y;
	}
}

Direction CentipedeBody::getDir()
{
	return _dir;
}

void CentipedeBody::display(IGraphicHandler *lib)
{
	lib->drawRectangle(_pos, t_Vector2i(CENTIPEDE_SIZE_X, CENTIPEDE_SIZE_Y), t_Color(0, 255, 0));
}
