//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4030
//

#include <iostream>
#include "C4030.hpp"
#include "Exception.hpp"

void C4030::dump() const
{
	std::cout << "C4030" << std::endl;
}

void C4030::initOutputMap()
{
	_outputMap[2] = std::make_pair(0, 1);
	_outputMap[3] = std::make_pair(4, 5);
	_outputMap[9] = std::make_pair(7, 8);
	_outputMap[10] = std::make_pair(11, 12);
}

void C4030::initValidPin()
{
	_validPin.push_back(3);
	_validPin.push_back(4);
	_validPin.push_back(10);
	_validPin.push_back(11);
}

void C4030::initPins()
{
	std::size_t i = 0;

	while (i < _nbPins)
		_pins[i++] = nullptr;
}

C4030::C4030(nts::Tristate &value) : Component()
{
	_value = value;
	_nbPins = 14;
	initOutputMap();
	initValidPin();
	initPins();
}

C4030::~C4030()
{}

nts::IComponent** C4030::getPins() const
{
	return (nts::IComponent**)_pins;
}

std::size_t C4030::getOtherPin(std::size_t pin, bool _switch)
{
	if (_switch)
		return _linked[_outputMap[pin - 1].first + 1];
	return _linked[_outputMap[pin - 1].second + 1];
}

bool C4030::checkNotNull(std::size_t pin)
{
	if (_pins[_outputMap[pin - 1].first] == nullptr ||
	    _pins[_outputMap[pin - 1].second] == nullptr)
		return false;
	return true;
}

nts::Tristate C4030::compute(std::size_t pin)
{
	nts::Tristate _v1;
	nts::Tristate _v2;

	if (pin > _nbPins)
		throw (PinError(UNKNOWN_PIN));
	try {
		if (checkValidPin(pin) && checkNotNull(pin))
			if (_outputMap.find(pin - 1) != _outputMap.end()) {
				_v1 = _pins[_outputMap[pin - 1].first]
					->compute(getOtherPin(pin, true));
				_v2 = _pins[_outputMap[pin - 1].second]
					->compute(getOtherPin(pin, false));
				return xor_gate(_v1, _v2);
			}
		if (!checkValidPin(pin))
			throw (LinkError(WRONG_LINK));
		return nts::UNDEFINED;
	} catch (NtsError const &e) {
		throw (e);
	}
}
