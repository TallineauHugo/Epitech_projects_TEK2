//
// EPITECH PROJECT, 2018
// nano
// File description:
// true
//

#pragma once

#include "Component.hpp"

class True : virtual public Component
{
public:
	True();
	~True();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t);
private:
	nts::IComponent* _pins[1];
};
