//
// EPITECH PROJECT, 2018
// arcade
// File description:
// nibbler
//

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "ArcadeError.hpp"
#include "NibblerGameHandler.hpp"

NibblerGameHandler::NibblerGameHandler() : _speed(0), _stock(3), _turbo(false)
{
	std::ifstream file(HIGHSCORE_FILE);

	_highscore = 0;
	if (!file.is_open())
		throw ArcadeError("Can't find 'highscore/highscore.nibbler' file !\n");
	file >> _highscore;
}

void NibblerGameHandler::collideFood(t_Vector2i pos)
{
	_stock += 1;
	_food->removeFood(pos);
	_snake->addScore(100);
	generateFood();	
}

void NibblerGameHandler::collideTmpFood(t_Vector2i pos)
{
	_stock += rand() % MAX_NEW_CELL + 1;
	_tmpFood->removeFood(pos);
	_snake->addScore(200);
}

bool NibblerGameHandler::updateSnakePos()
{
	std::list<Cell*> _list = _snake->getCellList();
	Cell *tail = _list.back();
	Cell *head = _list.front();

	if (_map->at(head->_pos) == WALL || _map->at(head->_pos) == SNAKE)
		return false;
	else if (_map->at(head->_pos) == FOOD)
		collideFood(head->_pos);
	else if (_map->at(head->_pos) == TMP_FOOD)
		collideTmpFood(head->_pos);
	else
		_map->setValue(tail->_oldPos, EMPTY);
	_map->setValue(head->_pos, SNAKE);
	_map->setValue(tail->_oldPos, EMPTY);
	return true;
}

void NibblerGameHandler::generateFood()
{
	s_Vector2i v;

	v.x = rand() % (_map->getSize().x - 1);
	v.y = rand() % (_map->getSize().y - 1);
	while (_map->at(v) != EMPTY) {
		v.x = rand() % _map->getSize().x;
		v.y = rand() % _map->getSize().y;
	}
	_map->setValue(v, FOOD);
	_food->addFood(v);
}

bool NibblerGameHandler::initFoodByMap()
{
	t_Vector2i tmp;
	bool ret = false;
	t_Vector2i size = _map->getSize();

	tmp.x = tmp.y = 0;
	while (tmp.x < size.x) {
		while (tmp.y < size.y) {
			if (_map->at(tmp) == FOOD) {
				_food->addFood(tmp);
				ret = true;
			}
			tmp.y += 1;
		}
		tmp.y = 0;
		tmp.x += 1;
	}
	return ret;
}

void NibblerGameHandler::init()
{
	srand(time(NULL));
	_map = new Map;
	if (!(_map->checkSnake()))
		throw ArcadeError(BAD_SNAKE);
	_snake = new Snake(_map->getStartingPos());
	_food = new Food;
	_tmpFood = new TemporaryFood;
	if (!initFoodByMap())
		throw ArcadeError(BAD_FOOD);
}

void NibblerGameHandler::restart()
{
	exitLib();
	init();
	_speed = 0;
	_turbo = false;
	_stock = 3;
}

void NibblerGameHandler::handleKey(KeyInput::Key key)
{
	if (key == KeyInput::Left)
		_snake->rotate(LEFT);
	else if (key == KeyInput::Right)
		_snake->rotate(RIGHT);
	else if (key == KeyInput::Up)
		_snake->rotate(UP);
	else if (key == KeyInput::Down)
		_snake->rotate(DOWN);
	else if (key == KeyInput::Space)
		_turbo = !_turbo;	
}

void NibblerGameHandler::generateTemporaryFood()
{
	s_Vector2i v;

	v.x = rand() % (_map->getSize().x - 1);
	v.y = rand() % (_map->getSize().y - 1);
	while (_map->at(v) != EMPTY) {
		v.x = rand() % _map->getSize().x;
		v.y = rand() % _map->getSize().y;
	}
	_map->setValue(v, TMP_FOOD);
	_tmpFood->addFood(v);
}

void NibblerGameHandler::update(KeyInput::Key key)
{
	handleKey(key);
	if (rand() % 20 == 0)
		generateTemporaryFood();
	_tmpFood->handleTemporaryFood();
	if (_stock > 0) {
		_snake->addCell();
		_map->setValue(_snake->getCellList().back()->_pos, SNAKE);
		_stock--;
	}
	_snake->move();
	if (!updateSnakePos())
		restart();
}

void NibblerGameHandler::displayScore(IGraphicHandler *lib) const
{
	t_Vector2i pos(0, 0);
	std::stringstream s;
	std::size_t score = _snake->getScore();
	std::size_t highscore = (score > _highscore) ? score : _highscore;

	s << "Score: ";
	s << score;
	s << " | Highscore: ";
	s << highscore;
	s << " | Speed: ";
	s << _speed;
	s << " Km/h";
	lib->writeText(pos, s.str());
}

void NibblerGameHandler::speedHandler()
{
	int time = 0;

	time = (_snake->getLength() * 2000);
	if (_turbo)
		time *= 2;
	_speed = time / 100;
	usleep(60000 - time);
}

void NibblerGameHandler::display(IGraphicHandler *lib)
{
	_map->display(lib);
	_food->display(lib);
	_tmpFood->display(lib);
	_snake->display(lib);
	displayScore(lib);
	speedHandler();
	lib->refresh();
}

void NibblerGameHandler::writeHighScore() const
{
	std::ofstream file(HIGHSCORE_FILE, std::ios::out | std::ios::trunc);

	if (file)
		file << _snake->getScore();
	else
		throw ArcadeError("Can't open 'highscore.nibbler' file !\n");
}

void NibblerGameHandler::exitLib()
{
	if (_snake->getScore() > _highscore)
		writeHighScore();
	delete _map;
	delete _food;
	delete _snake;
}

extern "C"
{
	__attribute__((constructor)) void constructor(void)
	{
	}

	__attribute__((destructor)) void destructor(void)
	{
	}

	NibblerGameHandler* entryPoint()
	{
		NibblerGameHandler *ret = new NibblerGameHandler;
		return (ret);
	}
}
