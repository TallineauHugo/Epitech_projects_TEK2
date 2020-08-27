//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4004
//

#include "C4004.hpp"

void C4004::dump() const
{
	std::cout << "C4004" << std::endl;
}

C4004::C4004(nts::Tristate &value) : Component()
{
	this->_value = value;
	_nbPins = 14;
}

C4004::~C4004()
{}

nts::IComponent** C4004::getPins() const
{
	return (nts::IComponent**)_pins;
}

nts::Tristate C4004::compute(std::size_t pin)
{
	return nts::UNDEFINED;		        
}
