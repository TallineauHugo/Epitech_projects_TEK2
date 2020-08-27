//
// EPITECH PROJECT, 2018
// nano
// File description:
// clock
//

#pragma once

#include "Component.hpp"

class Clock : virtual public Component
{
public:
	Clock(nts::Tristate&);
	~Clock();

	void dump() const;
	nts::Tristate compute(std::size_t pin = 1);
	nts::IComponent** getPins() const;
private:
	nts::IComponent* _pins[1];
};
