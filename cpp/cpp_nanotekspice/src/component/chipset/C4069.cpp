//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4069
//

#include <iostream>
#include "C4069.hpp"
#include "Exception.hpp"

void C4069::dump() const
{
	std::cout << "C4069" << std::endl;
}

void C4069::initOutputMap()
{
	_outputMap[1] = 0;
	_outputMap[3] = 2;
	_outputMap[5] = 4;
	_outputMap[7] = 8;
	_outputMap[9] = 10;
	_outputMap[11] = 12;
}

void C4069::initValidPin()
{
	_validPin.push_back(2);
	_validPin.push_back(4);
	_validPin.push_back(6);
	_validPin.push_back(8);
	_validPin.push_back(10);
	_validPin.push_back(12);
}

void C4069::initPins()
{
	std::size_t i = 0;

	while (i < _nbPins)
		_pins[i++] = nullptr;
}

C4069::C4069(nts::Tristate &value) : Component()
{
	_value = value;
	_nbPins = 14;
	initOutputMap();
	initValidPin();
	initPins();
}

C4069::~C4069()
{}

nts::IComponent** C4069::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4069::compute(std::size_t pin)
{
	nts::Tristate _v1;

	if (pin > _nbPins)
		throw (PinError(UNKNOWN_PIN));
	try {
		if (checkValidPin(pin) && _pins[_outputMap[pin - 1]]) {
			_v1 = _pins[_outputMap[pin - 1]]
				->compute(_linked[_outputMap[pin - 1] + 1]);
			if (_v1 != nts::UNDEFINED)
				_v1 = (_v1) ? nts::FALSE : nts::TRUE;
			return _v1;
		}
		if (!checkValidPin(pin))
			throw (LinkError(WRONG_LINK));
		return nts::UNDEFINED;
	} catch (NtsError const &e) {
		throw (e);
	}
}
