//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Centipede
//

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "Object.hpp"
#include "GraphicElements.hpp"
#include "CentipedeGameHandler.hpp"
#include "CentipedeBody.hpp"

class Centipede : public virtual Object
{
public:
	Centipede(int life = 1, t_Vector2i pos = t_Vector2i(0, 0), int size = 8);
	~Centipede();
	void move(CentipedeGameHandler&);
	void display(IGraphicHandler *);
        void splice(std::list<CentipedeBody>::iterator,
			 CentipedeGameHandler&);
	std::list<CentipedeBody> _body;
	void setDir(Direction);
	Direction getDir();
	
private:
	void chain_move(CentipedeGameHandler&);

	Direction _dir;
	int down = 0;
};

#endif
