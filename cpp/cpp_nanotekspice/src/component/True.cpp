//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "Exception.hpp"
#include "True.hpp"

True::True() : Component()
{
	this->_value = nts::TRUE;
}

True::~True()
{}

nts::IComponent** True::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate True::compute(std::size_t pin)
{
	if (pin != 1)
		throw (PinError(UNKNOWN_PIN));
	return nts::TRUE;
}
