//
// EPITECH PROJECT, 2018
// nano
// File description:
// 2716
//

#pragma once

#include "Component.hpp"

class C2716 : virtual public Component
{
public:
	C2716(nts::Tristate &value);
	~C2716();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
private:
	void initValidPin();
	
	nts::IComponent* _pins[24];
};
