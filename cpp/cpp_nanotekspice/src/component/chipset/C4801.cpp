//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4801
//

#include "C4801.hpp"

C4801::C4801(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 14;
}

C4801::~C4801()
{}

nts::IComponent** C4801::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4801::compute(std::size_t pin)
{
	return nts::UNDEFINED;
}
