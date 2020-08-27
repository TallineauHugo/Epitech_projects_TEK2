//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4040
//

#pragma once

#include <tuple>
#include "Component.hpp"
#include "FlipFlop.hpp"

class C4040 : virtual public Component
{
public:
	C4040(nts::Tristate &value);
	~C4040();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
	void dump() const;
private:
	void initOutputMap();
	void initValidPin();
	void initPins();
	nts::Tristate exec(std::size_t);

	nts::IComponent* _pins[16];
	std::unordered_map<std::size_t, std::size_t> _outputMap;
	std::unordered_map<std::size_t, FlipFlop*> _ffMap;
};
