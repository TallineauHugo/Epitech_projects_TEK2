//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede Game Handler
//

#pragma once

#include <list>
#include <vector>
#include <algorithm>
#include <functional>
#include "Input.hpp"
#include "State.hpp"
#include "Directions.hpp"
#include "Player.hpp"
#include "CentipedeGameHandler.hpp"
#include "Box.hpp"
#include "Bullet.hpp"
#include "Object.hpp"
#include "GraphicElements.hpp"
#include "IGameHandler.hpp"

class Centipede;
class Bullet;
class Player;

class CentipedeGameHandler : public virtual IGameHandler
{
public:
	CentipedeGameHandler();
	~CentipedeGameHandler();
	void init();
	void update(KeyInput::Key);
	void display(IGraphicHandler *);
	void exitLib() {};
	void setState(State);
	void detectTarget(Bullet&);
	void launchCentipede();
	int  check_boxes(t_Vector2i, t_Vector2i);
	t_Vector2i getMapsize();
	int hitCentipede(t_Vector2i, t_Vector2i,
			 std::vector<Centipede>::iterator);
	int hitBox(t_Vector2i, t_Vector2i, std::vector<Box>::iterator);
	void displayScore(IGraphicHandler *);
	void addBox(Box);
	void addCentipede(Centipede);
	void lost();
	void putBoxes();
	std::vector<Centipede> getCent();

private:	
	Player *_player;
	State _state = RUNNING;
	size_t _score = 0;
	t_Vector2i Mapsize;
	std::vector<Box> _boxes;
	std::vector<Centipede> _centipedes; 
};
