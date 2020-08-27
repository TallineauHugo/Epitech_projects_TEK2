//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#pragma once

#include <map>
#include "Food.hpp"

class TemporaryFood : public Food
{
public:
	TemporaryFood();
	~TemporaryFood();
public:
	void handleTemporaryFood();
	void addFood(t_Vector2i);
	void display(IGraphicHandler*) const;
	std::list<std::pair<t_Vector2i, int>>::iterator removeFood(t_Vector2i);
private:
	std::list<std::pair<t_Vector2i, int>> _tmpFoodList;
};
