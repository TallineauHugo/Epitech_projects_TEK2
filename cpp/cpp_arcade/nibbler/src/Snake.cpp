//
// EPITECH PROJECT, 2018
// nibbler
// File description:
// snake
//

#include "Snake.hpp"

void Snake::addScore(std::size_t toAdd)
{
	_score += toAdd;
}

Snake::Snake(t_Vector2i pos) : _length(1), _head(nullptr), _direction(UP)
{
	_cellList.push_back(new Head(pos));
	_head = (Head*)_cellList.front();
	_score = 0;
}

Snake::~Snake()
{
}

std::size_t Snake::getLength() const
{
	return _length;
}

t_Vector2i Snake::getNextPos() const
{
	t_Vector2i pos(_head->_pos.x, _head->_pos.y);

	switch (_direction) {
	case LEFT:
		pos.x -= 1;
		break;
	case UP:
		pos.y -= 1;
		break;
	case RIGHT:
		pos.x += 1;
		break;
	case DOWN:
		pos.y += 1;
		break;
	}
	return pos;
}

void Snake::move()
{
	std::list<Cell*>::iterator t = _cellList.begin();
	t_Vector2i tmp;

	tmp.x = -1;
	tmp.y = -1;
	while (t != _cellList.end()) {
		(*t)->_oldPos = (*t)->_pos;
		(*t)->_pos = (*t)->_nextPos;
		if (tmp.x == -1)
			(*t)->_nextPos = getNextPos();
		else
			(*t)->_nextPos = tmp;
		tmp = (*t)->_pos;
		t++;
	}
}

std::size_t Snake::getScore() const
{
	return _score;
}

t_Vector2i Snake::getNewCellPos(t_Vector2i pos, t_Vector2i last) const
{
	t_Vector2i ret;

	ret.x = pos.x;
	ret.y = pos.y;
	if (pos.x != last.x)
		ret.x = (pos.x > last.x) ? pos.x + 1 : pos.x - 1;		
	else
		ret.y = (pos.y > last.y) ? pos.y + 1 : pos.y - 1;
	return ret;
}

void Snake::addCell()
{
	Cell *last = _cellList.back();
	Cell *_new = nullptr;
	t_Vector2i pos;
	
	if (last->_oldPos.x == -1 && last->_oldPos.y == -1) {
		pos = last->_pos;
		pos.y += 1;
	}
	else
		pos = last->_oldPos;
	_new = new Cell(pos);
	_new->_nextPos = last->_pos;
	_new->_oldPos = getNewCellPos(pos, last->_pos);
	_cellList.push_back(_new);
	_length += 1;
}

void Snake::rotate(Direction dir)
{
	if (dir % 2 == _direction % 2)
		return;
	_direction = dir;
	_head->_nextPos = _head->_pos;
	switch (dir) {
	case UP:
		_head->_nextPos.y -= 1;
		break;
	case DOWN:
		_head->_nextPos.y += 1;
		break;
	case RIGHT:
		_head->_nextPos.x += 1;
		break;
	case LEFT:
		_head->_nextPos.x -= 1;
		break;
	}
}

void Snake::display(IGraphicHandler *lib) const
{
	std::list<Cell*>::const_iterator t = _cellList.begin();

	while (t != _cellList.end()) {
		(*t)->display(lib);
		t++;
	}
}

std::list<Cell*> Snake::getCellList() const
{
	return _cellList;
}

Head *Snake::getHead() const
{
	return _head;
}
