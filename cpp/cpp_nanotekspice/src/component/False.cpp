//
// EPITECH PROJECT, 2018
// nano
// File description:
// false
//

#include "Exception.hpp"
#include "False.hpp"

False::False() : Component()
{
	this->_value = nts::FALSE;
}

False::~False()
{}

nts::IComponent** False::getPins() const
{
	return (nts::IComponent**)_pins;
}



nts::Tristate False::compute(std::size_t pin)
{
	if (pin != 1)
		throw (PinError(UNKNOWN_PIN));
	return nts::FALSE;
}
