//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#pragma once

#include <list>
#include "GraphicElements.hpp"

class Food
{
public:
	Food();
	~Food();
public:
	void display(IGraphicHandler*) const;
	void addFood(t_Vector2i);
	void removeFood(t_Vector2i);
protected:
	std::list<t_Vector2i> _foodList;
	s_Color _col;
};
