//
// EPITECH PROJECT, 2018
// nano
// File description:
// componentFactory
//

#include "ComponentFactory.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "C4071.hpp"
#include "C4069.hpp"
#include "C4001.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4081.hpp"
#include "C4008.hpp"
#include "C4040.hpp"
#include "C4013.hpp"

void ComponentFactory::initFunc()
{	
	_func[C_4001] = std::bind(&ComponentFactory::create4001,
				  this, std::placeholders::_1);
	_func[C_4011] = std::bind(&ComponentFactory::create4011,
				  this, std::placeholders::_1);
	_func[C_4030] = std::bind(&ComponentFactory::create4030,
				  this, std::placeholders::_1);
	_func[C_4081] = std::bind(&ComponentFactory::create4081,
				  this, std::placeholders::_1);
	_func[C_4008] = std::bind(&ComponentFactory::create4008,
				  this, std::placeholders::_1);
}

ComponentFactory::ComponentFactory()
{
	_func[INPUT] = std::bind(&ComponentFactory::createInput,
				   this, std::placeholders::_1);
     	_func[OUTPUT] = std::bind(&ComponentFactory::createOutput,
				    this, std::placeholders::_1);
	_func[CLOCK] = std::bind(&ComponentFactory::createClock,
				   this, std::placeholders::_1);
	_func[STR_TRUE] = std::bind(&ComponentFactory::createTrue,
				  this, std::placeholders::_1);
	_func[STR_FALSE] = std::bind(&ComponentFactory::createFalse,
				   this, std::placeholders::_1);
	_func[C_4071] = std::bind(&ComponentFactory::create4071,
				  this, std::placeholders::_1);
	_func[C_4040] = std::bind(&ComponentFactory::create4040,
				  this, std::placeholders::_1);
	_func[C_4013] = std::bind(&ComponentFactory::create4013,
				  this, std::placeholders::_1);
	_func[C_4069] = std::bind(&ComponentFactory::create4069,
				  this, std::placeholders::_1);
	initFunc();
}

ComponentFactory::~ComponentFactory()
{}

std::unique_ptr<nts::IComponent> ComponentFactory::createInput
(const std::string &value)
	const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new Input(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::createOutput
(const std::string &value)
	const noexcept
{
	std::unique_ptr<nts::IComponent> tmp(new Output());

	return tmp;
	(void)value;
}

std::unique_ptr<nts::IComponent> ComponentFactory::createClock
(const std::string &value)
	const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new Clock(_converted));

	return tmp;
	(void)value;
}

std::unique_ptr<nts::IComponent> ComponentFactory::createTrue
(const std::string &value)
	const noexcept
{
	std::unique_ptr<nts::IComponent> tmp(new True());

	return tmp;
	(void)value;
}

std::unique_ptr<nts::IComponent> ComponentFactory::createFalse
(const std::string &value) const noexcept
{
	std::unique_ptr<nts::IComponent> tmp(new False());

	return tmp;
	(void)value;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4071
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4071(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4069
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4069(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4001
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4001(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4011
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4011(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4030
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4030(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4081
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4081(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4008
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4008(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4040
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4040(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::create4013
(const std::string &value) const noexcept
{
	nts::Tristate _converted = (value == "0") ? nts::FALSE : nts::TRUE;
	std::unique_ptr<nts::IComponent> tmp(new C4013(_converted));

	return tmp;
}

std::unique_ptr<nts::IComponent> ComponentFactory::createComponent
(const std::string &type, const std::string &value)
{
	return _func[type](value);
}

bool ComponentFactory::checkType(const std::string type)
{
	if (_func.find(type) == _func.end())
		return false;
	return true;
}
