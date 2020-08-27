//
// EPITECH PROJECT, 2018
// arcade
// File description:
// lib loader
//

#ifndef _DLLOADER_
#define _DLLOADER_

#include <algorithm>
#include <list>
#include <iostream>
#include <map>

#include "Input.hpp"
#include "IGameHandler.hpp"
#include "GraphicElements.hpp"
#include "Menu.hpp"

#define WIDTH 50
#define HEIGHT 50

class DLLoader
{
private:
	void					*_gameHandler;
	void					*_graphHandler;
	IGameHandler				*_game;
	IGraphicHandler				*_graph;
	t_Vector2i				_size;
	std::list<std::string>			_gameList;
	std::list<std::string>			_graphList;
	std::list<std::string>::iterator	_graphIt;
	std::list<std::string>::iterator	_gameIt;
	Menu					_menu;
	typedef void	(DLLoader::*fcn)();
	std::map<KeyInput::Key, fcn>		_keyBinding;
	
public:
	DLLoader();
	~DLLoader();
	void	initGame();
	void	initGraph(const char *);
	void	initListGame();
	void	initListGraph();
	void	play();
	void	close() const noexcept;
	void	menu(KeyInput::Key&);


	void	nextGame();
	void	previousGame();
	void	nextGraph();
	void	previousGraph();
};

#endif // _DLLOADER_
