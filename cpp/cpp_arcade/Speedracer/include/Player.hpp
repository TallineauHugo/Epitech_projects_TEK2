//
// EPITECH PROJECT, 2018
// arcade
// File description:
// SpeedRacer Player
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Input.hpp"
#include "GraphicElements.hpp"

#define MAPSIZE_X 50
#define MAPSIZE_Y 50
#define PLAYER_SIZE_X 2
#define PLAYER_SIZE_Y 2

class Player
{
public:
	Player(t_Vector2i, KeyInput::Key, KeyInput::Key);
	~Player();
	void update(KeyInput::Key);
	void display(IGraphicHandler *, int);
	bool getWon();
	void setWon(bool);
	void setPos(t_Vector2i);

private:
	t_Vector2i _pos;
	KeyInput::Key _key1;
	KeyInput::Key _key2;
	bool _right;
	bool _won;
};

#endif
