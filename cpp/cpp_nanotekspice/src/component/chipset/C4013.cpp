//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4013
//

#include <iostream>
#include "C4013.hpp"
#include "Exception.hpp"

void C4013::dump() const
{
	std::cout << ": C4013" << std::endl;
}

void C4013::initOutputMap()
{
	_outputMap[0] = std::make_tuple(2, 3, 4, 5);
	_outputMap[1] = std::make_tuple(2, 3, 4, 5);
	_outputMap[11] = std::make_tuple(10, 9, 8, 7);
	_outputMap[12] = std::make_tuple(10, 9, 8, 7);
}

void C4013::initValidPin()
{
	_validPin.push_back(1);
	_validPin.push_back(2);
	_validPin.push_back(12);
	_validPin.push_back(13);
}

void C4013::initPins()
{
	std::size_t i = 0;

	while (i < _nbPins)
		_pins[i++] = nullptr;
	_pinValue[1] = nts::UNDEFINED;
	_pinValue[2] = nts::UNDEFINED;
	_pinValue[12] = nts::UNDEFINED;
	_pinValue[13] = nts::UNDEFINED;
}

C4013::C4013(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 14;
	initOutputMap();
	initValidPin();
	initPins();
}

C4013::~C4013()
{}

nts::IComponent** C4013::getPins() const
{
	return (nts::IComponent**)_pins;
}

bool C4013::checkNotNull(std::size_t pin)
{
	std::tuple<std::size_t, std::size_t, std::size_t, std::size_t> a;

	a = _outputMap[pin - 1];
	if (_pins[std::get<0>(a)] == nullptr ||
	    _pins[std::get<1>(a)] == nullptr ||
	    _pins[std::get<2>(a)] == nullptr ||
	    _pins[std::get<3>(a)] == nullptr)
		return false;
	return true;
}

nts::Tristate C4013::handleReset(std::size_t pin, nts::Tristate _r, nts::Tristate _s)
{
	if (_s && isQ(pin))
		return _s;
	return _r;
}

nts::Tristate C4013::getOutputValue(nts::Tristate _clock, nts::Tristate _data, std::size_t pin)
{
	if (!_clock)
		return _pinValue[pin];
	if (isQ(pin)) {
		_pinValue[pin] = _data;
		return _data;
	}
	_pinValue[pin] = (_data) ? nts::FALSE : nts::TRUE;
	return _pinValue[pin];
}

bool C4013::isQ(std::size_t pin)
{
	if (pin == 1 || pin == 13)
		return true;
	return false;
}

nts::Tristate C4013::exec(std::size_t pin)
{
	nts::Tristate _c;
	nts::Tristate _r;
	nts::Tristate _d;
	nts::Tristate _s;
	std::tuple<std::size_t, std::size_t, std::size_t, std::size_t> a;

	a = _outputMap[pin - 1];
	_c = _pins[std::get<0>(a)]
		->compute(_linked[std::get<0>(a) + 1]);
	_r = _pins[std::get<1>(a)]
		->compute(_linked[std::get<1>(a) + 1]);
	_d = _pins[std::get<2>(a)]
		->compute(_linked[std::get<2>(a) + 1]);
	_s = _pins[std::get<3>(a)]
		->compute(_linked[std::get<3>(a) + 1]);
	if ((_r && !isQ(pin)) || (_s && isQ(pin)))
		return handleReset(pin, _r, _s);
	return getOutputValue(_c, _d, pin);
}

nts::Tristate C4013::compute(std::size_t pin)
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
