//
// EPITECH PROJECT, 2018
// nano
// File description:
// 4008
//

#pragma once

#include <tuple>
#include "Component.hpp"

class C4008 : virtual public Component
{
public:
	C4008(nts::Tristate &value);
	~C4008();

	nts::IComponent** getPins() const;

	nts::Tristate compute(std::size_t pin = 1) override;
	void dump() const;
private:
	void simulateOutput(nts::Tristate, nts::Tristate);
	void initOutputMap();
	void initValidPin();
	void initPins();
	bool checkNotNull(std::size_t);
	nts::Tristate manageCarry(nts::Tristate, nts::Tristate, std::size_t);
	nts::Tristate exec(std::size_t);

	nts::Tristate _cout;
	nts::IComponent* _pins[16];
	std::unordered_map<std::size_t, std::tuple<std::size_t,
						   std::size_t,
						   std::size_t>> _outputMap;
};
