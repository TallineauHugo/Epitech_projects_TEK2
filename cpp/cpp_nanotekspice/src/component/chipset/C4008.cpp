//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4008
//

#include <iostream>
#include "C4008.hpp"
#include "Input.hpp"
#include "Exception.hpp"

void C4008::dump() const
{
	std::cout << "C4008" << std::endl;
}

void C4008::initOutputMap()
{
	_outputMap[13] = std::make_tuple(12, 0, 0);
	_outputMap[12] = std::make_tuple(14, 0, 11);
	_outputMap[11] = std::make_tuple(1, 2, 10);
	_outputMap[10] = std::make_tuple(3, 4, 9);
	_outputMap[9] = std::make_tuple(5, 6, 8);
}

void C4008::initValidPin()
{
	_validPin.push_back(14);
	_validPin.push_back(13);
	_validPin.push_back(12);
	_validPin.push_back(11);
	_validPin.push_back(10);
}

void C4008::initPins()
{
	std::size_t i = 0;

	while (i < _nbPins)
		_pins[i++] = nullptr;
}

C4008::C4008(nts::Tristate &value) : Component()
{
	_value = value;
	_nbPins = 16;
	initOutputMap();
	initValidPin();
	initPins();
	_cout = nts::UNDEFINED;
}

C4008::~C4008()
{
}

nts::IComponent** C4008::getPins() const
{
	return (nts::IComponent**)_pins;
}

void C4008::simulateOutput(nts::Tristate _v1, nts::Tristate _v2)
{
	if (_cout == true && (_v1 > 0 || _v2 > 0))
		_cout = nts::TRUE;
	else if (_cout == false && _v1 > 0 && _v2 > 0)
		_cout = nts::TRUE;
	else
		_cout = nts::FALSE;
}

bool C4008::checkNotNull(std::size_t pin)
{
	std::tuple<std::size_t, std::size_t, std::size_t> a;

	a = _outputMap[pin - 1];
	if (_pins[std::get<0>(a)] == nullptr ||
	    _pins[std::get<1>(a)] == nullptr ||
	    _pins[std::get<2>(a)] == nullptr)
		return false;
	return true;

}

nts::Tristate C4008::manageCarry(nts::Tristate _v1, nts::Tristate _v2, std::size_t pin)
{
	nts::Tristate ret;

	if (pin == 14)
		return _cout;
	ret = xor_gate(_v1, _v2);
	if (ret != nts::UNDEFINED) {
		if (_cout == true)
			ret = (ret == nts::TRUE) ? nts::FALSE : nts::TRUE;
		simulateOutput(_v1, _v2);
	}
	return ret;
}

nts::Tristate C4008::exec(std::size_t pin)
{
	nts::Tristate _v1;
	nts::Tristate _v2;
	nts::Tristate _v3;
	std::tuple<std::size_t, std::size_t, std::size_t> a;

	a = _outputMap[pin - 1];
	_v1 = _pins[std::get<0>(a)]
		->compute(_linked[std::get<0>(a) + 1]);
	_v2 = _pins[std::get<1>(a)]
		->compute(_linked[std::get<1>(a) + 1]);
	_v3 = _pins[std::get<2>(a)]
		->compute(_linked[std::get<2>(a) + 1]);
	_cout = (pin == 10) ? _v3 : _cout;
	return manageCarry(_v1, _v2, pin);
}

nts::Tristate C4008::compute(std::size_t pin)
{
	if (pin > _nbPins)
		throw (PinError(UNKNOWN_PIN));
	try {
		if (checkValidPin(pin) && checkNotNull(pin))
			return exec(pin);
		if (!checkValidPin(pin))
			throw (LinkError(WRONG_LINK));
		return nts::UNDEFINED;
	} catch (NtsError const &e) {
		throw (e);
	}
}
