//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4503
//

#include "C4503.hpp"

C4503::C4503(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 14;
}

C4503::~C4503()
{}

nts::IComponent** C4503::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4503::compute(std::size_t pin)
{
	return nts::UNDEFINED;
}
