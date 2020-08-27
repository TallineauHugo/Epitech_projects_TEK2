//
// EPITECH PROJECT, 2018
// nano
// File description:
// input
//

#include "Exception.hpp"
#include "Input.hpp"
#include <iostream>

Input::Input(nts::Tristate &value) : Component()
{
	_pins[0] = nullptr;
	_value = value;
}

Input::~Input()
{}

nts::IComponent** Input::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate Input::compute(std::size_t pin)
{
	if (pin != 1)
		throw (PinError(UNKNOWN_PIN));
	return getValue();
}
