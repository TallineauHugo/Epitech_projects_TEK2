//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4004
//

#pragma once

#include "Component.hpp"

class C4004 : virtual public Component
{
public:
	C4004(nts::Tristate &value);
	~C4004();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
	void dump() const;
private:
	nts::IComponent* _pins[16];
};
