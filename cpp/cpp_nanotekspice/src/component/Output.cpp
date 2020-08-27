//
// EPITECH PROJECT, 2018
// nano
// File description:
// output
//

#include <iostream>
#include "Exception.hpp"
#include "Output.hpp"

Output::Output() : Component()
{
	_pins[0] = nullptr;
}

Output::~Output()
{}

void Output::dump() const
{
	std::cout << "=";
	switch (this->_value) {
	case nts::UNDEFINED:
		std::cout << "U";
		break;
	case nts::TRUE:
		std::cout << "1";
		break;
	case nts::FALSE:
		std::cout << "0";
		break;
	}
	std::cout << std::endl;
}

nts::IComponent** Output::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate Output::compute(std::size_t pin)
{
	nts::Tristate value;

	if (pin != 1)
		throw (PinError(UNKNOWN_PIN));
	try {
		value = _pins[pin - 1]->compute(_linked[pin]);
	} catch (NtsError const &e) {
		throw (e);
	}
	_value = value;
	return _value;
}
