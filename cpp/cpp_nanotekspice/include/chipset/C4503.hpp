//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4503
//

#pragma once

#include "Component.hpp"

class C4503 : virtual public Component
{
public:
	C4503(nts::Tristate &value);
	~C4503();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
private:
	nts::IComponent* _pins[16];
};
