//
// EPITECH PROJECT, 2018
// nano
// File description:
// false
//

#pragma once

#include <unordered_map>
#include "IComponent.hpp"

class FlipFlop
{
public:
	FlipFlop(std::size_t id);
	~FlipFlop();

	nts::Tristate getValue() const;
	nts::Tristate compute(nts::IComponent*, std::unordered_map<std::size_t, FlipFlop*>);
private:
	std::size_t _id;
	nts::Tristate _value;
	
};
