//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Menu
//

#pragma once

#include <iostream>
#include <list>

#include "GraphicElements.hpp"
#include "Input.hpp"

class Menu
{
public:
	Menu();
	~Menu();
	void setGameList(std::list<std::string>);
	std::string update(KeyInput::Key, IGraphicHandler *);
	void move(KeyInput::Key, IGraphicHandler *);
	void display(IGraphicHandler *);
private:

	void displayLogo(std::string, IGraphicHandler *, int);
	void displayLine(std::string, IGraphicHandler *, int);
	std::string getGameName();
	std::list<std::string>	_gameList;
	std::list<std::string>::iterator _gameIt;
};
