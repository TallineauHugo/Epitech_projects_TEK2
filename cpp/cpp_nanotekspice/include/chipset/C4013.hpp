//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4013
//

#pragma once

#include "Component.hpp"

class C4013 : virtual public Component
{
public:
	C4013(nts::Tristate &value);
	~C4013();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
	void dump() const;
private:
	void initOutputMap();
	void initValidPin();
	void initPins();

	nts::Tristate exec(std::size_t);
	nts::Tristate getOutputValue(nts::Tristate, nts::Tristate, std::size_t);
	nts::Tristate handleReset(std::size_t, nts::Tristate, nts::Tristate);

	bool isQ(std::size_t);
	bool checkNotNull(std::size_t);

	nts::IComponent* _pins[14];
	std::unordered_map<std::size_t,
			   std::tuple<std::size_t,
				      std::size_t,
				      std::size_t,
				      std::size_t>> _outputMap;
	std::unordered_map<std::size_t, nts::Tristate> _pinValue;
};
