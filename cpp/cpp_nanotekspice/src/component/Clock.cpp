//
// EPITECH PROJECT, 2018
// nano
// File description:
// clock
//

#include <iostream>
#include "Exception.hpp"
#include "Clock.hpp"

Clock::Clock(nts::Tristate &value) : Component()
{
	_pins[0] = nullptr;
	_value = value;
}

Clock::~Clock()
{
}

nts::IComponent** Clock::getPins() const
{
	return (nts::IComponent**)_pins;
}

void Clock::dump() const
{
	std::string value = (_value) ? "1" : "0";

	if (_value == nts::UNDEFINED)
		value = "U";
	std::cout << "=" << value << std::endl;
}

nts::Tristate Clock::compute(std::size_t pin)
{
	if (pin == 0) {
		this->_value = (this->_value == nts::TRUE) ? nts::FALSE : nts::TRUE;
		return nts::UNDEFINED;
	}
	else {
		if (pin != 1)
			throw (PinError(UNKNOWN_PIN));
		nts::Tristate tmp = getValue();
		if (tmp == nts::UNDEFINED)
			throw (PinError(UNDEFINED_PIN));
		return tmp;
	}
}
