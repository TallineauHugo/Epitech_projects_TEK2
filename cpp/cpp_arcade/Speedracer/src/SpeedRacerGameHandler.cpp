//
// EPITECH PROJECT, 2018
// arcade
// File description:
// SpeedRacer SpeedRacerGameHandler
//

#include <fstream>
#include <vector>
#include <iostream>
#include "ArcadeError.hpp"
#include "Player.hpp"
#include "SpeedRacerGameHandler.hpp"

#define HIGHSCORE "highscore/speedracer.highscore"

SpeedRacerGameHandler::SpeedRacerGameHandler() :
	_p1(Player(t_Vector2i(0, MAPSIZE_Y / 2 - 5), KeyInput::Left, KeyInput::Right)),
	_p2(Player(t_Vector2i(0, MAPSIZE_Y / 2 + 5), KeyInput::Q, KeyInput::D))
{
}

SpeedRacerGameHandler::~SpeedRacerGameHandler()
{
}

void SpeedRacerGameHandler::init()
{
	gettimeofday(&_start, NULL);
}

void SpeedRacerGameHandler::display(IGraphicHandler *graph)
{
	std::string str("time : ");

	str += std::to_string(_chrono / 10000000) + ".";
	if (_chrono % 100 < 10)
		str += "0" + std::to_string(_chrono % 100);
	else
		str += std::to_string(_chrono % 100);
	graph->cleanScreen();
	_p1.display(graph, 1);
	_p2.display(graph, 2);
	graph->writeText(t_Vector2i(MAPSIZE_X / 2 - 4, MAPSIZE_Y / 5), str);
	graph->refresh();
}

void SpeedRacerGameHandler::update(KeyInput::Key key)
{
	struct timeval now;
	long start = _start.tv_usec / 10000 + _start.tv_sec * 10000000;
	long tmp;

	gettimeofday(&now, NULL);
	tmp = now.tv_usec / 10000 + now.tv_sec * 10000000;
	_chrono = tmp - start;
	if (key == KeyInput::Q || key == KeyInput::D)
		_p2.update(key);
	else if (key == KeyInput::Left || key == KeyInput::Right)
		_p1.update(key);
	if (_p2.getWon() || _p1.getWon())
		endGame();
}

void SpeedRacerGameHandler::endGame()
{
	_p1.setPos(t_Vector2i(0, MAPSIZE_Y / 2 - 5));
	_p2.setPos(t_Vector2i(0, MAPSIZE_Y / 2 + 5));
	_p1.setWon(false);
	_p2.setWon(false);
	gettimeofday(&_start, NULL);
}


extern "C"
{
	__attribute__((constructor)) void constructor(void)
	{
	}

	__attribute__((destructor)) void destructor(void)
	{
	}

	SpeedRacerGameHandler* entryPoint()
	{
		return (new SpeedRacerGameHandler);
	}
}
