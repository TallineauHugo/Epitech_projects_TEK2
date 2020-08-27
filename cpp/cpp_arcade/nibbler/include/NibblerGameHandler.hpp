//
// EPITECH PROJECT, 2018
// arcade
// File description:
// nibbler
//

#pragma once

#include <sstream>
#include "IGameHandler.hpp"
#include "Map.hpp"
#include "Snake.hpp"
#include "TemporaryFood.hpp"
#include "MapCell.hpp"

#define HIGHSCORE_FILE "highscore/highscore.nibbler"
#define MAX_NEW_CELL 3

class NibblerGameHandler : virtual public IGameHandler
{
public:
	NibblerGameHandler();
	virtual ~NibblerGameHandler() = default;
public:
	void init();
	void update(KeyInput::Key);
	void display(IGraphicHandler*);
	void exitLib();
private:
	bool updateSnakePos();
	bool initFoodByMap();
	void generateFood();
	void displayScore(IGraphicHandler*) const;
	void speedHandler();
	void restart();
	void handleKey(KeyInput::Key);
	void generateTemporaryFood();
	void collideFood(t_Vector2i);
	void collideTmpFood(t_Vector2i);
	void writeHighScore() const;
private:
	std::size_t _speed;
	std::size_t _highscore;
	int _mapWidth;
	int _mapLength;
	int _ratio;
	int _stock;
	bool _turbo;
	
	s_Vector2i _origin;

	Map *_map;
	Snake *_snake;
	Food *_food;
	TemporaryFood *_tmpFood;
};
