//
// EPITECH PROJECT, 2018
// nano
// File description:
// flipflop
//

#include "FlipFlop.hpp"

FlipFlop::FlipFlop(std::size_t id) : _id(id), _value(nts::FALSE)
{	
}

FlipFlop::~FlipFlop()
{
}

nts::Tristate FlipFlop::getValue() const
{
	return _value;
}

nts::Tristate FlipFlop::compute(nts::IComponent* c,
				std::unordered_map<std::size_t,
				FlipFlop*> _ffMap)
{
	nts::Tristate clock;
	
	if (_id == 0)
		clock = (c->compute(10)) ? nts::FALSE : nts::TRUE;
	else
		clock = _ffMap[_id - 1]->compute(c, _ffMap);
	if (clock == nts::FALSE) {
		_value = (_value) ? nts::FALSE : nts::TRUE;
	}
	return getValue();
}
