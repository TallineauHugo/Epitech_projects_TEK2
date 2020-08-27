//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Menu
//

#include "Menu.hpp"
#include "DLLoader.hpp"
#include "GraphicElements.hpp"
#include "ArcadeError.hpp"

#include <fstream>
#include <iostream>
#include <list>

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::setGameList(std::list<std::string> list)
{
	_gameList = list;
	_gameIt = _gameList.begin();
}

void Menu::move(KeyInput::Key key, IGraphicHandler *lib)
{
	if (key == KeyInput::Left){
		if (_gameIt == _gameList.begin())
			_gameIt = _gameList.end();
		_gameIt--;
	}
	else {
		_gameIt++;
		if (_gameIt == _gameList.end())
			_gameIt= _gameList.begin();
	}
	display(lib);
}

std::string Menu::getGameName()
{
	std::string res;
	std::size_t found = (*_gameIt).find_last_of('_');

	res = _gameIt->substr(found + 1);
	res = res.substr(0, res.size() - 3);
	return res;
}

std::string Menu::update(KeyInput::Key key, IGraphicHandler *lib)
{
	if (key == KeyInput::Return)
		return (*_gameIt);
	else if (key == KeyInput::Left || key == KeyInput::Right)
		move(key, lib);
	return ("");
}

void Menu::displayLine(std::string tmp, IGraphicHandler *lib, int y)
{
	int i = 0;

	for (i = 0; tmp[i] != '\0' && tmp[i] != '\n'; i++) {
		if (tmp[i] != ' ')
			lib->putPixel(t_Vector2i((WIDTH / 2) - (tmp.size() / 2) + i, y), t_Color());
	}
}

void Menu::displayLogo(std::string name, IGraphicHandler *lib, int y)
{
	std::ifstream file("./logo/" + name);
	std::string tmp;

	if (!file.is_open())
		throw ArcadeError("Can't find logo game file !\n");
	while (!file.eof()) {
		getline(file, tmp);
		displayLine(tmp, lib, y);
		y++;
	}
}

void Menu::display(IGraphicHandler *lib)
{
	std::string name;
	
	lib->cleanScreen();
	displayLogo("arcade", lib, 0);
	name = getGameName();
	displayLogo(name, lib, 20);
	lib->writeText(t_Vector2i((WIDTH / 2) - (name.size() / 2), 35),
		       "<" + name + ">");
	lib->refresh();
}
