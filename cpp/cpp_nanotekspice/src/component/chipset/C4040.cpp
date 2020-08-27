//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4040
//

#include <iostream>
#include "C4040.hpp"
#include "Exception.hpp"
#include "FlipFlop.hpp"

void C4040::initOutputMap()
{
	_outputMap[0] = 11;
	_outputMap[1] = 5;
	_outputMap[2] = 4;
	_outputMap[3] = 6;
	_outputMap[4] = 3;
	_outputMap[5] = 2;
	_outputMap[6] = 1;
	_outputMap[8] = 0;
	_outputMap[11] = 8;
	_outputMap[12] = 7;
	_outputMap[13] = 9;
	_outputMap[14] = 10;
}

void C4040::initValidPin()
{
	_validPin.push_back(1);
	_validPin.push_back(2);
	_validPin.push_back(3);
	_validPin.push_back(4);
	_validPin.push_back(5);
	_validPin.push_back(6);
	_validPin.push_back(7);
	_validPin.push_back(9);
	_validPin.push_back(10);
	_validPin.push_back(11);
	_validPin.push_back(12);
	_validPin.push_back(13);
	_validPin.push_back(14);
	_validPin.push_back(15);
}

void C4040::initPins()
{
	std::size_t i = 0;

	while (i < _nbPins)
		_pins[i++] = nullptr;

	_ffMap[0] = new FlipFlop(0);
	_ffMap[1] = new FlipFlop(1);
	_ffMap[2] = new FlipFlop(2);
	_ffMap[3] = new FlipFlop(3);
	_ffMap[4] = new FlipFlop(4);
	_ffMap[5] = new FlipFlop(5);
	_ffMap[6] = new FlipFlop(6);
	_ffMap[7] = new FlipFlop(7);
	_ffMap[8] = new FlipFlop(8);
	_ffMap[9] = new FlipFlop(9);
	_ffMap[10] = new FlipFlop(10);
	_ffMap[11] = new FlipFlop(11);	
}

void C4040::dump() const
{
	std::cout << "C4040" << std::endl;
}

C4040::C4040(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 16;
	initOutputMap();
	initValidPin();
	initPins();
}

C4040::~C4040()
{
	std::size_t i = 0;

	while (i < 12)
		delete _ffMap[i++];
}

nts::IComponent** C4040::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4040::exec(std::size_t pin)
{
	return _ffMap[_outputMap[pin]]->compute(this, _ffMap);
}

nts::Tristate C4040::compute(std::size_t pin)
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
