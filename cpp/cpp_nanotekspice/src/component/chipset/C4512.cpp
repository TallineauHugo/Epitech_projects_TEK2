//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4512
//

#include "C4512.hpp"

C4512::C4512(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 14;
}

C4512::~C4512()
{}

nts::IComponent** C4512::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4512::compute(std::size_t pin)
{
	return nts::UNDEFINED;
}
