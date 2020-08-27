//
// EPITECH PROJECT, 2018
// arcade
// File description:
// lib loader
//

#include <dlfcn.h>

#include <cstring>
#include <dirent.h>
#include <unistd.h>

#include <iostream>

#include "IGameHandler.hpp"
#include "GraphicElements.hpp"
#include "DLLoader.hpp"
#include "ArcadeError.hpp"

//default width and height are 0 to set the size as full screen
DLLoader::DLLoader()
{
	this->_size.x = WIDTH;
	this->_size.y = HEIGHT;
	this->_keyBinding.insert(std::make_pair(KeyInput::PageDown, &DLLoader::previousGame));
	this->_keyBinding.insert(std::make_pair(KeyInput::PageUp, &DLLoader::nextGame));
	this->_keyBinding.insert(std::make_pair(KeyInput::End, &DLLoader::previousGraph));
	this->_keyBinding.insert(std::make_pair(KeyInput::Home, &DLLoader::nextGraph));
}

DLLoader::~DLLoader()
{
	
}

void	DLLoader::initGame()
{
	char		*error;
	IGameHandler	*(*entry)();

	this->_gameHandler = dlopen(_gameIt->c_str(), RTLD_LAZY);
	error = dlerror();
	if (!this->_gameHandler)
		throw ArcadeError(error);
	entry = (IGameHandler *(*)())dlsym(this->_gameHandler, "entryPoint");
	error = dlerror();
	if (error)
		throw ArcadeError(error);
	this->_game = (*entry)();
	free(error);
}

void	DLLoader::initGraph(const char *lib_name)
{
	char		*error;
	IGraphicHandler	*(*entry)();

	this->_graphHandler = dlopen(lib_name, RTLD_LAZY);
	error = dlerror();
	if (!this->_graphHandler)
		throw ArcadeError(error);
	entry = (IGraphicHandler *(*)())dlsym(this->_graphHandler, "entryPoint");
	error = dlerror();
	if (error)
		throw ArcadeError(error);
	this->_graph = (*entry)();
	free(error);
}

//reading into the ./games file and fill a list of games.
void	DLLoader::initListGame()
{
	DIR	*directory = opendir("./games");
	struct dirent	*files;

	if (!directory)
		throw ArcadeError("./games : No such file or directory");
	while ((files = readdir(directory)) != NULL) {
		if (strncmp(files->d_name, "lib_arcade_", 11) == 0)
			this->_gameList.push_back("./games/" + *new std::string(files->d_name));
	}
	this->_gameIt = this->_gameList.begin();
	closedir(directory);
}

void	DLLoader::initListGraph()
{
	DIR	*directory = opendir("./lib");
	struct dirent	*files;

	if (!directory) {
		throw ArcadeError("./lib : No such file or directory");
	}
	while ((files = readdir(directory)) != NULL) {
		if (strncmp(files->d_name, "lib_arcade_", 11) == 0)
			this->_graphList.push_back("./lib/" + *new std::string(files->d_name));
	}
	this->_graphIt = this->_graphList.begin();
	closedir(directory);
}

void	DLLoader::menu(KeyInput::Key &input)
{
	std::string game("");

	_menu.setGameList(_gameList);
	_menu.display(_graph);
	while (game.empty()) {
		input = _graph->getInput();
		if (input == KeyInput::Escape)
			return;
		if (input == KeyInput::Home || input == KeyInput::End) {
			(this->*this->_keyBinding[input])();
			_menu.display(_graph);
		}
		game = _menu.update(input, _graph);
		usleep(50000);
	}
	while (*_gameIt != game)
		nextGame();
}

//key handling and display handling
void	DLLoader::play()
{
	KeyInput::Key	input = KeyInput::M;
	fcn		f;

	this->_graph->init();
	this->_game->init();
	this->_graph->createWindow(this->_size);
	menu(input);
	while (input != KeyInput::Escape) {
		input = this->_graph->getInput();
		if (input == KeyInput::M)
			menu(input);				
		if (this->_keyBinding.find(input) != this->_keyBinding.end()) {
			f = this->_keyBinding[input];
			(this->*f)();
		}
		this->_game->update(input);
		this->_game->display(this->_graph);
		usleep(5000);
	}
}

//loading next game
void	DLLoader::nextGame()
{
	char		*error;
	IGameHandler	*(*entry)();

	this->_gameIt++;
	if (this->_gameIt == this->_gameList.end())
		this->_gameIt = this->_gameList.begin();
	this->_game->exitLib();
	dlclose(this->_gameHandler);
	this->_gameHandler = dlopen((*this->_gameIt).c_str(), RTLD_LAZY);
	error = dlerror();
	if (!this->_gameHandler)
		throw ArcadeError(error);
	entry = (IGameHandler *(*)())dlsym(this->_gameHandler, "entryPoint");
	error = dlerror();
	if (error)
		throw ArcadeError(error);
	this->_game = (*entry)();
	this->_game->init();
	free(error);
}

//loading previous game
void	DLLoader::previousGame()
{
	char		*error;
	IGameHandler	*(*entry)();

	if (this->_gameIt == this->_gameList.begin())
		this->_gameIt = this->_gameList.end();
	this->_gameIt--;
	this->_game->exitLib();
	dlclose(this->_gameHandler);
	this->_gameHandler = dlopen((*this->_gameIt).c_str(), RTLD_LAZY);
	error = dlerror();
	if (!this->_gameHandler)
		throw ArcadeError(error);
	entry = (IGameHandler *(*)())dlsym(this->_gameHandler, "entryPoint");
	error = dlerror();
	if (error)
		throw ArcadeError(error);
	this->_game = (*entry)();
	this->_game->init();
	free(error);
}

//loading next graph lib
void	DLLoader::nextGraph()
{
	char		*error;
	IGraphicHandler	*(*entry)();

	this->_graphIt++;
	if (this->_graphIt == this->_graphList.end())
		this->_graphIt = this->_graphList.begin();
	this->_graph->exitLib();
	dlclose(this->_graphHandler);
	this->_graphHandler = dlopen((*this->_graphIt).c_str(), RTLD_LAZY);
	error = dlerror();
	if (!this->_graphHandler)
		throw ArcadeError(error);
	entry = (IGraphicHandler *(*)())dlsym(this->_graphHandler, "entryPoint");
	error = dlerror();
	if (error)
		throw ArcadeError(error);
	this->_graph = (*entry)();
	this->_graph->init();
	this->_graph->createWindow(this->_size);
	free(error);
}

//loading previous graph lib
void	DLLoader::previousGraph()
{
	char		*error;
	IGraphicHandler	*(*entry)();

	if (this->_graphIt == this->_graphList.begin())
		this->_graphIt = this->_graphList.end();
	this->_graphIt--;
	this->_graph->exitLib();
	dlclose(this->_graphHandler);
	this->_graphHandler = dlopen((*this->_graphIt).c_str(), RTLD_LAZY);
	error = dlerror();
	if (!this->_graphHandler)
		throw ArcadeError(error);
	entry = (IGraphicHandler *(*)())dlsym(this->_graphHandler, "entryPoint");
	error = dlerror();
	if (error)
		throw ArcadeError(error);
	this->_graph = (*entry)();
	this->_graph->init();
	this->_graph->createWindow(this->_size);
	free(error);
}

void	DLLoader::close() const noexcept
{
	this->_game->exitLib();
	this->_graph->exitLib();
	dlclose(this->_gameHandler);
	dlclose(this->_graphHandler);
}
