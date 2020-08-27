//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4030
//

#pragma once

#include "Component.hpp"

class C4030 : virtual public Component
{
public:
	C4030(nts::Tristate &value);
	~C4030();

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
