//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4017
//

#include "C4017.hpp"

void C4017::initOutputMap()
{
	_outputMap[0] = std::make_tuple(12, 13, 14);
	_outputMap[1] = std::make_tuple(12, 13, 14);
	_outputMap[2] = std::make_tuple(12, 13, 14);
	_outputMap[3] = std::make_tuple(12, 13, 14);
	_outputMap[4] = std::make_tuple(12, 13, 14);
	_outputMap[5] = std::make_tuple(12, 13, 14);
	_outputMap[6] = std::make_tuple(12, 13, 14);
	_outputMap[7] = std::make_tuple(12, 13, 14);
	_outputMap[9] = std::make_tuple(12, 13, 14);
	_outputMap[10] = std::make_tuple(12, 13, 14);
	_outputMap[11] = std::make_tuple(12, 13, 14);
}

void C4017::initValidPin()
{
	_validPin.push_back(1);
	_validPin.push_back(2);
	_validPin.push_back(3);
	_validPin.push_back(4);
	_validPin.push_back(5);
	_validPin.push_back(6);
	_validPin.push_back(7);
	_validPin.push_back(8);
	_validPin.push_back(10);
	_validPin.push_back(11);
	_validPin.push_back(12);
}

void C4017::initPins()
{
	std::size_t i = 0;

	while (i < _nbPins)
		_pins[i++] = nullptr;
}

void C4017::dump() const
{
	std::cout << "C4017" << std::endl;
}

C4017::C4017(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 14;
	initOutputMap();
	initValidPin();
	initPins();
}

C4017::~C4017()
{}

nts::IComponent** C4017::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4017::compute(std::size_t pin)
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
