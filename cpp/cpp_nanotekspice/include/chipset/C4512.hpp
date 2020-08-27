//
// EPITECH PROJECT, 2018
// nanp
// File description:
// 4512
//

#pragma once

#include "Component.hpp"

class C4512 : virtual public Component
{
public:
	C4512(nts::Tristate &value);
	~C4512();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
private:
	nts::IComponent* _pins[16];
};
