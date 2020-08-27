//
// EPITECH PROJECT, 2018
// nano
// File description:
// component
//

#include <iostream>
#include "Exception.hpp"
#include "Component.hpp"

Component::Component() : _value(nts::UNDEFINED), _nbPins(1)
{
}

Component::~Component()
{}

bool Component::checkValidPin(std::size_t pin)
{
	std::vector<std::size_t>::iterator it = _validPin.begin();

	while (it != _validPin.end()) {
		if (pin == *it)
			return true;
		it++;
	}
	return false;
}

std::size_t Component::getNbPins() const
{
	return _nbPins;
}

nts::Tristate Component::getValue() const
{
	return _value;
}

void Component::setValue(nts::Tristate value)
{
	this->_value = value;
}

nts::IComponent* Component::operator[](size_t index)
{
	return getPins()[index];
}

void Component::setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin)
{
	if (pin > this->_nbPins)
	        throw (PinError(UNKNOWN_PIN));
	getPins()[pin - 1] = &other;
	_linked[pin] = otherPin;
}

void Component::dump() const
{
	std::string value = (_value == nts::TRUE) ? "1" : "0";

	if (_value == nts::UNDEFINED)
		value = "U";
	std::cout << ": " << value << std::endl;;
}

nts::Tristate Component::inverter_gate(nts::Tristate a)
{
	if (a == nts::UNDEFINED)
		return nts::UNDEFINED;
	return (a == nts::TRUE) ? nts::FALSE : nts::TRUE;
}

nts::Tristate Component::or_gate(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::TRUE || b == nts::TRUE)
		return nts::TRUE;
	if (a == nts::UNDEFINED || b == nts::UNDEFINED) {
		return nts::UNDEFINED;
	}
	return (a || b) ? nts::TRUE : nts::FALSE;
}

nts::Tristate Component::nor_gate(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::TRUE || b == nts::TRUE)
		return nts::FALSE;
	if (a == nts::UNDEFINED || b == nts::UNDEFINED) {
		return nts::UNDEFINED;
	}
	return (!(a || b)) ? nts::TRUE : nts::FALSE;
}

nts::Tristate Component::xor_gate(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED)
		return nts::UNDEFINED;
	return (a == b) ? nts::FALSE : nts::TRUE;
}

nts::Tristate Component::and_gate(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED) {
		return nts::UNDEFINED;
	}
	return (a && b) ? nts::TRUE : nts::FALSE;
}

nts::Tristate Component::nand_gate(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::UNDEFINED || b == nts::UNDEFINED)
		return nts::UNDEFINED;
	return (a && b) ? nts::FALSE : nts::TRUE;
}
