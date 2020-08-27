//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Player
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Object.hpp"
#include "Bullet.hpp"
#include "GraphicElements.hpp"
#include "CentipedeGameHandler.hpp"
#include "Directions.hpp"
#include <iostream>
#include <map>

class CentipedeGameHandler;
class CentipedeBody;
class Bullet;

class Player : public virtual Object
{
public:
	Player(t_Vector2i pos = t_Vector2i(0, 0));
	~Player();
public:
	void move(KeyInput::Key, CentipedeGameHandler&);
	void shoot();
	void detectHit(CentipedeGameHandler&);
        void moveBullet();
	void display(IGraphicHandler *);
	Bullet *getBullet();
	static std::map<KeyInput::Key, Direction> _mvmts;
private:
	void hitCentipede(std::list<CentipedeBody>, CentipedeGameHandler&);
	Bullet *_bullet;
};

#endif
