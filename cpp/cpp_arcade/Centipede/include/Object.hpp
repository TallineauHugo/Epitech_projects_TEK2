//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Object
//

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "GraphicElements.hpp"

#define PLAYER_SIZE_X 3
#define PLAYER_SIZE_Y 3
#define CENTIPEDE_SIZE_X 2
#define CENTIPEDE_SIZE_Y 2
#define BULLET_SIZE_X 1
#define BULLET_SIZE_Y 1

class Object
{
public:
	Object(int life = 0, t_Vector2i pos = t_Vector2i(0, 0));
	void display(IGraphicHandler *);
	t_Vector2i& getPos();
	void setPos(t_Vector2i);
	int getLife();
	void loseLife();
	void setLife(int);
protected:
	int             _life;
	t_Vector2i      _pos;
};

#endif
