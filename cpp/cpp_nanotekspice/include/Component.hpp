//
// EPITECH PROJECT, 2018
// nano
// File description:
// component
//

#pragma once

#include <unordered_map>
#include <vector>
#include "IComponent.hpp"

class Component : public nts::IComponent
{
public:
	Component();
	~Component();

	nts::Tristate getValue() const;
	virtual nts::IComponent** getPins() const = 0;
	std::size_t getNbPins() const;

	void setValue(nts::Tristate value);
	void setLink(std::size_t pin, nts::IComponent &other, std::size_t
		     otherPin) override;

	nts::IComponent* operator[](std::size_t);

	virtual nts::Tristate compute(std::size_t pin = 1) = 0;
	void dump() const override;

	nts::Tristate or_gate(nts::Tristate a, nts::Tristate b);
	nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b);
	nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b);
	nts::Tristate nand_gate(nts::Tristate a, nts::Tristate b);
	nts::Tristate and_gate(nts::Tristate a, nts::Tristate b);
	nts::Tristate inverter_gate(nts::Tristate);
protected:
	bool checkValidPin(std::size_t);

	nts::Tristate _value;
	std::size_t _nbPins;
	std::unordered_map<std::size_t, std::size_t> _linked;
	std::unordered_map<std::size_t, std::pair<std::size_t,
						  std::size_t>> _outputMap;
	std::vector<std::size_t> _validPin;
};
