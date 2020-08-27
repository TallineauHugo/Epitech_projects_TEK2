//
// EPITECH PROJECT, 2018
// nano
// File description:
// input
//

#pragma once

#include "Component.hpp"

class Input : virtual public Component
{
public:
	Input(nts::Tristate&);
	~Input();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1);
private:
	nts::IComponent* _pins[1];
};
