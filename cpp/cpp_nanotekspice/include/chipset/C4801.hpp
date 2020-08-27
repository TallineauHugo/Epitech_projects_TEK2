//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4801
//

#pragma once

#include "Component.hpp"

class C4801 : virtual public Component
{
public:
	C4801(nts::Tristate &value);
	~C4801();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
private:
	nts::IComponent* _pins[24];
};
