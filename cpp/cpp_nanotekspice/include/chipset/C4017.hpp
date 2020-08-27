//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4017
//

#pragma once

#include "Component.hpp"

class C4017 : virtual public Component
{
public:
	C4017(nts::Tristate &value);
	~C4017();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
private:
	void initOutputMap();
	void initValidPin();
	void initPins();

	nts::IComponent* _pins[15];
	std::unordered_map<std::size_t,
			   std::tuple<std::size_t, std::size_t,
				      std::size_t>> _outputMap;
};
