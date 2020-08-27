//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Player SpeedRacer
//

#include "Player.hpp"
#include <iostream>

Player::Player(t_Vector2i pos, KeyInput::Key key1, KeyInput::Key key2) :
	_pos(pos), _key1(key1), _key2(key2)
{
}

Player::~Player()
{
}

void Player::update(KeyInput::Key key)
{
	if (key == _key1 && _right == false) {
		_pos.x++;
		_right = true;
	}
	else if (key == _key2 && _right == true) {
		_pos.x++;
		_right = false;
	}
	_won = (_pos.x == MAPSIZE_X - PLAYER_SIZE_X) ? true : false;
}

void Player::display(IGraphicHandler *lib, int player)
{
	if (player == 1)
		lib->drawRectangle(_pos,
				   t_Vector2i(PLAYER_SIZE_X, PLAYER_SIZE_Y),
				   t_Color());
	else
		lib->drawRectangle(_pos,
				   t_Vector2i(PLAYER_SIZE_X, PLAYER_SIZE_Y),
				   t_Color(0, 255, 0));		
}

void Player::setPos(t_Vector2i pos)
{
	_pos = pos;
}

bool Player::getWon()
{
	return _won;
}

void Player::setWon(bool state)
{
	_won = state;
}
