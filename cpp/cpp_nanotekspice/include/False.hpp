//
// EPITECH PROJECT, 2018
// nano
// File description:
// false
//

#pragma once

#include "Component.hpp"

class False : virtual public Component
{
public:
	False();
	~False();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t);
private:
	nts::IComponent* _pins[1];
};
