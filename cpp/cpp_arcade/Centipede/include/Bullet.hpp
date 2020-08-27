//
// EPITECH PROJECT, 2018
// Arcade
// File description:
// Centipede Bullet
//

#ifndef BULLET_HPP_
#define BULLET_HPP_

#include "Object.hpp"
#include "GraphicElements.hpp"
#include "CentipedeGameHandler.hpp"

class CentipedeGameHandler;

class Bullet : public virtual Object
{
public:
	Bullet();
	~Bullet();
	void moveForward();
	void detectHit(CentipedeGameHandler&);
	bool getShot();
	void setShot(bool);
	void display(IGraphicHandler *lib);
		
private:
	bool _shot = false;
};

#endif
