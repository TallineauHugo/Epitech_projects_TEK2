//
// EPITECH PROJECT, 2018
// nibbler
// File description:
// snake
//

#pragma once

#include <list>
#include "Head.hpp"

class Snake
{
public:
	Snake(s_Vector2i);
	~Snake();
public:
	void move();
	void addCell();
	void rotate(Direction);
	void display(IGraphicHandler*) const;
	std::list<Cell*> getCellList() const;
	std::size_t getLength() const;
	std::size_t getScore() const;
	void addScore(std::size_t);

	Head *getHead() const;
private:
	t_Vector2i getNextPos() const;
	t_Vector2i getNewCellPos(t_Vector2i, t_Vector2i) const;
	
	std::list<Cell*> _cellList;
	std::size_t _length;
	std::size_t _score;

	Head *_head;
	Direction _direction;
};
