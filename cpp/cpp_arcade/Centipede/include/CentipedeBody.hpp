//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Body
//

#pragma once

#include "Object.hpp"
#include "Directions.hpp"
#include "CentipedeGameHandler.hpp"

class CentipedeBody : public virtual Object
{
public:
	CentipedeBody(t_Vector2i pos = t_Vector2i(0, 0));
	~CentipedeBody();
	void move(CentipedeGameHandler&);
	void move2(CentipedeGameHandler&);
	void setDown(int);
	void setNextPos(t_Vector2i);
	t_Vector2i getNextPos();
	Direction getDir();
	void display(IGraphicHandler *lib);
private:
	Direction _dir;
	int down = 0;
	t_Vector2i nextPos;
};
