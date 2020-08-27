//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4514
//

#pragma once

#include "Component.hpp"

class C4514 : virtual public Component
{
public:
	C4514(nts::Tristate &value);
	~C4514();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
	void dump() const;
private:
	void initOutputMap();
	void initValidPin();
	void initPins();

	nts::IComponent* _pins[24];
};
