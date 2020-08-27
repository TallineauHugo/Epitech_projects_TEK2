//
// EPITECH PROJECT, 2018
// nibbler
// File description:
// cell
//

#pragma once

#include "GraphicElements.hpp"

enum Direction
{
	LEFT,
	UP,
	RIGHT,
	DOWN
};

class Cell
{
public:
	Cell(s_Vector2i);
	~Cell();
public:
	void display(IGraphicHandler*) const;
public:
	t_Vector2i _pos;
	t_Vector2i _nextPos;
	t_Vector2i _oldPos;
	t_Color _col;
};
