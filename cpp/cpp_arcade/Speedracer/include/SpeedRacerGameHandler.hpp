//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Speedracer Game Handler
//

#pragma once

#include <sys/time.h>
#include <vector>
#include "GraphicElements.hpp"
#include "IGameHandler.hpp"

class SpeedRacerGameHandler : public virtual IGameHandler
{
public:
	SpeedRacerGameHandler();
	~SpeedRacerGameHandler();
	void init();
	void endGame();
	void update(KeyInput::Key);
	void display(IGraphicHandler *);
	void exitLib() {};

private:
	Player _p1;
	Player _p2;
	struct timeval _start;
	int _chrono;
};
