//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Centipede CentipedeGameHandler
//

#include "Centipede.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include "CentipedeGameHandler.hpp"

CentipedeGameHandler::CentipedeGameHandler()
{
	_player = new Player;
	Mapsize.x = 50;
	Mapsize.y = 48;
}

CentipedeGameHandler::~CentipedeGameHandler()
{
}

void CentipedeGameHandler::putBoxes()
{
	t_Vector2i tmp;
	
	while (_boxes.size() < 15) {
		tmp.x = (rand() % (Mapsize.x / CENTIPEDE_SIZE_X));
		tmp.x *= CENTIPEDE_SIZE_X;
		tmp.y =(rand() % (Mapsize.y / CENTIPEDE_SIZE_Y));
		tmp.y *= CENTIPEDE_SIZE_Y;
		addBox(Box(tmp));
	}
}

void CentipedeGameHandler::launchCentipede()
{
	t_Vector2i tmp(0, 0);
	std::vector<Box>::iterator it;

	while (_centipedes.size() == 0) {
		tmp.x = (rand() % (Mapsize.x / CENTIPEDE_SIZE_X));
		tmp.x *= CENTIPEDE_SIZE_X;
		for (it = _boxes.begin(); it != _boxes.end()
			     && !(it->getPos() == tmp); it++);
		if (it == _boxes.end())
			addCentipede(Centipede(5, tmp, 8));
	}
}

void CentipedeGameHandler::init()
{
	srand(time(NULL));
	putBoxes();
	launchCentipede();
	_player->setPos(t_Vector2i(25, 40));
}

void CentipedeGameHandler::display(IGraphicHandler *graph)
{
	std::vector<Centipede>::iterator it = _centipedes.begin();
	std::vector<Box>::iterator it2 = _boxes.begin();

	graph->cleanScreen();
	_player->display(graph);
	while (it != _centipedes.end()) {
		it->display(graph);
		it++;
	}
	while (it2 != _boxes.end()) {
		it2->display(graph);
		it2++;
	}
	it2++;
	if (_player->getBullet()->getShot() == true)
		_player->getBullet()->display(graph);
	displayScore(graph);
	graph->refresh();
}

void CentipedeGameHandler::displayScore(IGraphicHandler *graph)
{
	graph->drawRectangle(t_Vector2i(0, Mapsize.y),
			     t_Vector2i(Mapsize.x, 2), t_Color(255, 0, 0));
	graph->writeText(t_Vector2i(0, Mapsize.y), "Score: " + std::to_string(_score));
}

void CentipedeGameHandler::setState(State state)
{
	_state = state;
}

void CentipedeGameHandler::update(KeyInput::Key key)
{
	std::vector<Centipede>::iterator it = _centipedes.begin();

	_player->move(key, (*this));
	if (key == KeyInput::Space)
		_player->shoot();
	while (it != _centipedes.end()) {
		it->move((*this));
		if (it->_body.begin()->getPos().y >=
		    Mapsize.y - CENTIPEDE_SIZE_Y) {
			_score -= 100 * it->_body.size();
			it = _centipedes.erase(it);
		}
		else
			it++;
	}
	_player->moveBullet();
	_player->detectHit((*this));
	if (_centipedes.size() == 0)
		launchCentipede();
}

t_Vector2i CentipedeGameHandler::getMapsize()
{
	return Mapsize;
}

std::vector<Centipede> CentipedeGameHandler::getCent()
{
	return _centipedes;
}

int  CentipedeGameHandler::check_boxes(t_Vector2i pos, t_Vector2i size)
{
	std::vector<Box>::iterator it = _boxes.begin();
	
	if (pos.x + size.x > Mapsize.x || pos.x < 0
	    || pos.y + size.y > Mapsize.y || pos.y < 0)
		return 1;
	while (it != _boxes.end()) {
		if (((pos.x + size.x <= it->getPos().x + CENTIPEDE_SIZE_X
		      && pos.x + size.x > it->getPos().x)
		     || (pos.x < it->getPos().x + CENTIPEDE_SIZE_X
			 && pos.x >= it->getPos().x))
		    && ((pos.y + size.y <= it->getPos().y + CENTIPEDE_SIZE_Y
			 && pos.y + size.y > it->getPos().y)
			|| (pos.y < it->getPos().y + CENTIPEDE_SIZE_Y
			    && pos.y >= it->getPos().y)))
			return 1;
		it++;
	}
	return 0;
}

void CentipedeGameHandler::lost()
{
	_state = LOST;
	_centipedes.clear();
	_score = 0;
	_boxes.clear();
	init();
}

int CentipedeGameHandler::hitBox(t_Vector2i pos, t_Vector2i size,
				 std::vector<Box>::iterator it)
{
	if (((pos.x + size.x <= it->getPos().x + CENTIPEDE_SIZE_X
	      && pos.x + size.x > it->getPos().x)
	     || (pos.x < it->getPos().x + CENTIPEDE_SIZE_X
		 && pos.x >= it->getPos().x))
	    && ((pos.y + size.y <= it->getPos().y + CENTIPEDE_SIZE_Y
		 && pos.y + size.y > it->getPos().y)
		|| (pos.y < it->getPos().y + CENTIPEDE_SIZE_Y
		    && pos.y >= it->getPos().y))) {
		it->loseLife();
		if (it->getLife() == 0)
			_boxes.erase(it);
		return 1;
	}
	return 0;
}

int CentipedeGameHandler::hitCentipede(t_Vector2i pos, t_Vector2i size,
				       std::vector<Centipede>::iterator it)
{
	std::list<CentipedeBody>::iterator jt = it->_body.begin();
	
	while (jt != it->_body.end()) {
		if (((pos.x + size.x <= jt->getPos().x + CENTIPEDE_SIZE_X
		      && pos.x + size.x > jt->getPos().x)
		     || (pos.x < jt->getPos().x + CENTIPEDE_SIZE_X
			 && pos.x >= jt->getPos().x))
		    && ((pos.y + size.y <= jt->getPos().y + CENTIPEDE_SIZE_Y
			 && pos.y + size.y > jt->getPos().y)
			|| (pos.y < jt->getPos().y + CENTIPEDE_SIZE_Y
			    && pos.y >= jt->getPos().y))) {
			_score += 100;
		        it->splice(jt, (*this));
			if (it->_body.empty())
				it = _centipedes.erase(it);
			return 1;
		}
		jt++;
	}
	return 0;
}

void CentipedeGameHandler::detectTarget(Bullet& bullet)
{
	std::vector<Box>::iterator it = _boxes.begin();
	std::vector<Centipede>::iterator it2 = _centipedes.begin();
	t_Vector2i size(BULLET_SIZE_X, BULLET_SIZE_Y);
		
	while (it != _boxes.end()) {
		if (hitBox(bullet.getPos(), size, it)) {
			bullet.setShot(false);
			return;
		}
		it++;
	}
	while (it2 != _centipedes.end()) {
		if (hitCentipede(bullet.getPos(), size, it2)) {
			bullet.setShot(false);
			return;
		}
		it2++;
	}
}

void CentipedeGameHandler::addBox(Box box)
{
	for(unsigned i=0; i<_boxes.size(); i++){
		if (box.getPos() == _boxes[i].getPos())
			return;
	}
	_boxes.push_back(box);
}

void CentipedeGameHandler::addCentipede(Centipede cent)
{
	_centipedes.push_back(cent);
}

extern "C"
{
	__attribute__((constructor)) void constructor(void)
	{
	}

	__attribute__((destructor)) void destructor(void)
	{
	}

	CentipedeGameHandler* entryPoint()
	{
		return (new CentipedeGameHandler);
	}
}
