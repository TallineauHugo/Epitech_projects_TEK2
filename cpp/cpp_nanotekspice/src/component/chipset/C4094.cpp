//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4094
//

#include "C4094.hpp"

void C4094::dump() const
{
	std::cout << "C4094" << std::endl;
}

void C4094::initOutputMap()
{
	_outputMap[3] = std::make_tuple(0, 1, 2, 14);
	_outputMap[4] = std::make_tuple(0, 1, 2, 14);
	_outputMap[5] = std::make_tuple(0, 1, 2, 14);
	_outputMap[6] = std::make_tuple(0, 1, 2, 14);
	_outputMap[8] = std::make_tuple(0, 1, 2, 14);
	_outputMap[9] = std::make_tuple(0, 1, 2, 14);
	_outputMap[10] = std::make_tuple(0, 1, 2, 14);
	_outputMap[11] = std::make_tuple(0, 1, 2, 14);
	_outputMap[12] = std::make_tuple(0, 1, 2, 14);
	_outputMap[13] = std::make_tuple(0, 1, 2, 14);
}

void C4094::initValidPin()
{
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
}

void C4094::initPins()
{
	std::size_t i = 0;

	while (i < _nbPins)
		_pins[i++] = nullptr;
}

C4094::C4094(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 14;
	initOutputMap();
	initValidPin();
	initPins();
}

C4094::~C4094()
{}

nts::IComponent** C4094::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4094::compute(std::size_t pin)
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
