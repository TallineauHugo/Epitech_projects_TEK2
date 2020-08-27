//
// EPITECH PROJECT, 2018
// Centipede
// File description:
// Centipede
//

#include "Centipede.hpp"
#include "CentipedeBody.hpp"

Centipede::Centipede(int life, t_Vector2i pos, int size) : Object(life, pos)
{
	int i = 0;

	_dir = RIGHT;
	_body.resize(size, CentipedeBody(pos));
	std::list<CentipedeBody>::iterator it = _body.begin();
	while(it != _body.end()) {
		it->setPos(t_Vector2i(pos.x,
				      pos.y - CENTIPEDE_SIZE_Y * i));
		i++;
		it++;
	}
}

Centipede::~Centipede()
{
}

void Centipede::chain_move(CentipedeGameHandler& game)
{
	std::list<CentipedeBody>::iterator it = _body.end();
	std::list<CentipedeBody>::iterator it2;

	if (_body.size() <= 1)
		return;
	it--;
	it2 = it;
	it2--;
	while (it2 != _body.begin()) {
		it->move(game);
		if (it->getPos() == it->getNextPos())
			it->setNextPos(it2->getPos());
		it2--;
		it--;
		
	}
	if (it->getPos() == it->getNextPos())
		it->setNextPos(it2->getPos());
	it->move(game);
}

void Centipede::move(CentipedeGameHandler& game)
{
	t_Vector2i tmp;
	int i;

	tmp.x = _body.begin()->getPos().x;
	tmp.y = _body.begin()->getPos().y;
	if (down-- > 0)
		_body.begin()->getPos().y++;
	else if (_dir == LEFT)
		_body.begin()->getPos().x--;
	else
		_body.begin()->getPos().x++;
	i = game.check_boxes(_body.begin()->getPos(),
			     t_Vector2i(CENTIPEDE_SIZE_X, CENTIPEDE_SIZE_Y));
	if (i) {
		_body.begin()->setPos(tmp);
		_dir = (Direction)(((int)_dir + 2) % 4);
		down = CENTIPEDE_SIZE_Y;
	}
	chain_move(game);
}

void Centipede::display(IGraphicHandler *graph)
{
	std::list<CentipedeBody>::iterator it = _body.begin();

	if (_body.size() < 1)
		return;
	while (it != _body.end()) {
		it->display(graph);
		it++;
	}
	graph->drawRectangle(_body.begin()->getPos(),
			     t_Vector2i(CENTIPEDE_SIZE_X, CENTIPEDE_SIZE_Y),
			     t_Color(0, 255, 255));
}

void Centipede::splice(std::list<CentipedeBody>::iterator it,
			    CentipedeGameHandler& game)
{
	Direction tmp_dir = it->getDir();
	
	it->loseLife();
	if (it->getLife() != 0)
		return;
	game.addBox(Box(it->getPos()));
	it = _body.erase(it);
	if (it == _body.end())
		return;
	if (it == _body.begin())
		return;
	Centipede tmp(this->_life, it->getPos(), 1);
	it = _body.erase(it);
	std::list<CentipedeBody>::iterator it2 = tmp._body.begin();
	it2++;
	tmp._body.splice(it2, _body, it, _body.end());
	tmp.setDir(tmp_dir);
	if (!tmp._body.empty())
		game.addCentipede(tmp);
}

void Centipede::setDir(Direction dir)
{
	_dir = dir;
}

Direction Centipede::getDir()
{
	return _dir;
}
