//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4514
//

#include <iostream>
#include "Exception.hpp"
#include "C4514.hpp"

void initOutputMap()
{

}

void initValidPin()
{

}

void initPins()
{
	std::size_t i = 0;

	while (i < _nbPins)
		_pins[i++] = nullptr;
}

C4514::C4514(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 24;
	initOutputMap();
	initValidPin();
	initPins();
}

C4514::~C4514()
{}

nts::IComponent** C4514::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4514::compute(std::size_t pin)
{
	if (pin > _nbPins)
		throw (PinError(UNKNOWN_PIN));
	try {
		if (!checkValidPin(pin))
			throw (LinkError(WRONG_LINK));
		return nts::UNDEFINED;
	} catch (NtsError const& e) {
		throw (e);
	}
}
