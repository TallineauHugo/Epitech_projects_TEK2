//
// EPITECH PROJECT, 2018
// nano
// File description:
// componentFactory
//

#pragma once

#include <memory>
#include <functional>
#include <utility>
#include <unordered_map>
#include "IComponent.hpp"
#include "ComponentFactoryMacro.hpp"

class ComponentFactory
{
public:
	ComponentFactory();
	~ComponentFactory();

	std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);
	
	bool checkType(const std::string);
private:
	void initFunc();
	
	std::unique_ptr<nts::IComponent> createInput(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> createOutput(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> createClock(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> createTrue(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> createFalse(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4071(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4069(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4001(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4011(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4030(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4081(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4008(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4040(const std::string &value)
		const noexcept;
	std::unique_ptr<nts::IComponent> create4013(const std::string &value)
		const noexcept;

	std::unordered_map<std::string,
			   std::function<std::unique_ptr<nts::IComponent>
					 (const std::string&)>> _func;
};
