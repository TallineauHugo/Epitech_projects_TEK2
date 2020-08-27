//
// EPITECH PROJECT, 2018
// nano
// File description:
// 2716
//

#include "Exception.hpp"
#include "C2716.hpp"

void C2716::initValidPin()
{
	_validPin.push_back(9);
	_validPin.push_back(10);
	_validPin.push_back(11);
	_validPin.push_back(13);
	_validPin.push_back(14);
	_validPin.push_back(15);
	_validPin.push_back(16);
	_validPin.push_back(17);
}

C2716::C2716(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 14;
	initValidPin();
}

C2716::~C2716()
{}

nts::IComponent** C2716::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C2716::compute(std::size_t pin)
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
