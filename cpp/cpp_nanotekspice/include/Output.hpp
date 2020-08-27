//
// EPITECH PROJECT, 2018
// nano
// File description:
// output
//

#pragma once

#include "Component.hpp"

class Output : virtual public Component
{
public:
	Output();
	~Output();

	void dump() const;
	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1);
private:
	nts::IComponent* _pins[1];
};
