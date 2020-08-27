//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4069
//

#pragma once

#include "Component.hpp"

class C4069 : virtual public Component
{
public:
	C4069(nts::Tristate &value);
	~C4069();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
	void dump()const;
private:
	void initOutputMap();
	void initValidPin();
	void initPins();

	nts::IComponent* _pins[14];
	std::unordered_map<std::size_t, std::size_t> _outputMap;
};
