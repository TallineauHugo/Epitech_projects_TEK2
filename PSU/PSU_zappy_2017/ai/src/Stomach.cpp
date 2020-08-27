//
// EPITECH PROJECT, 2018
// zappy
// File description:
// stomach
//

#include "Stomach.hpp"

ai::Organs::Stomach::Stomach() : _food(10), _hungry(true)
{
}

ai::Organs::Stomach::~Stomach()
{
}

void ai::Organs::Stomach::updateFood(std::size_t newAmount)
{
	if (_hungry == true && newAmount >= 20)
		_hungry = false;
	else if (newAmount < 10)
		_hungry = true;
	_food = newAmount;
}

bool ai::Organs::Stomach::isHungry() const
{
	return _hungry;
}
