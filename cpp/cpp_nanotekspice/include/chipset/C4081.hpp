//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4081
//

#pragma once

#include "Component.hpp"

class C4081 : virtual public Component
{
public:
	C4081(nts::Tristate &value);
	~C4081();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
	void dump() const;
private:
	void initOutputMap();
	void initValidPin();
	void initPins();
	std::size_t getOtherPin(std::size_t, bool);
	bool checkNotNull(std::size_t);

	nts::IComponent* _pins[14];
};
