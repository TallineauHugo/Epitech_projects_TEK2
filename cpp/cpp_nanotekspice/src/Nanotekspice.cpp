//
// EPITECH PROJECT, 2018
// nano
// File description:
// nanotekspice
//

#include <iostream>
#include <string>
#include <signal.h>
#include <algorithm>
#include "Nanotekspice.hpp"

void Nanotekspice::removeSpaces(std::string &str)
{
	size_t index = 0;

	index = str.find("  ", index);
	while (index != std::string::npos) {
		str.replace(index, 2, SPACE);
		index = str.find("  ", 0);
	}
	if (str == EMPTY)
		return ;
	index = str.find(SPACE, 0);
	if (index == 0)
		str.replace(index, 1, EMPTY);
	index = str.find_last_of(SPACE);
	if (index == (str.size() - 1))
		str.replace(index, 1, EMPTY);
}

void Nanotekspice::replace(std::string &str, const std::string toReplace,
			   const std::string by, size_t len)
{
	size_t index = 0;

	while (1) {
		index = str.find(toReplace, index);
		if (index == std::string::npos)
			break;
		str.replace(index, len, by);
	}
}

void Nanotekspice::epurestr(std::string &str)
{
	this->replace(str, "#", EMPTY, std::string::npos);
	this->replace(str, TAB, SPACE, 1);
	this->replace(str, "\n", EMPTY, 1);
	this->removeSpaces(str);
}

bool Nanotekspice::isNumber(const std::string& buff)
{
	std::size_t i = 0;

	while (buff[i]) {
		if (!isdigit(buff[i]))
			return false;
		i++;
	}
	return true;
}

std::ifstream &Nanotekspice::getEpureLine(std::ifstream &file,
					  std::string &buff, char delim)
{
	buff = EMPTY;
	while (file && (buff == EMPTY || buff == "\n")) {
		getline(file, buff, delim);
		epurestr(buff);
	}
	return file;
}

std::istream &Nanotekspice::getEpureLine(std::istream &file,
					 std::string &buff, char delim)
{
	buff = EMPTY;
	while (file && (buff == EMPTY || buff == "\n")) {
		getline(file, buff, delim);
		epurestr(buff);
	}
	return file;
}

std::string Nanotekspice::getName(std::string &s)
{
	std::string r;

	r = s.substr(s.find(" ") + 1, s.find_last_of(":") - s.find(SPACE) - 1);
	return r;
}

std::size_t Nanotekspice::getPin(std::string &s, char delim)
{
	int pin = 0;
	std::string buff;

	if (delim == 1)
		buff = s.substr(s.find(LINK_SEPARATOR)
				+ 1, s.find(SPACE)
				- (s.find(LINK_SEPARATOR) + 1));
	else
		buff = s.substr(s.find_last_of(LINK_SEPARATOR) + 1,
				std::string::npos);
	if (!isNumber(buff))
		throw (SyntaxError(BAD_PIN_FORMAT));
	pin = stoi(buff, nullptr, 10);
	return (std::size_t)pin;
}

void Nanotekspice::addLinks(std::tuple<std::size_t, std::string,
			    std::size_t> a, std::tuple<std::size_t,
			    std::string, std::size_t> b)
{
	std::get<1>(a) =
		std::get<1>(a).substr(0, std::get<1>(a).find(LINK_SEPARATOR));
	_links[std::get<1>(b)].push_back(a);
	_links[std::get<1>(a)].push_back(b);
}

void Nanotekspice::parseLinks(std::ifstream &file)
{
	std::string s;
	std::string n1;
	std::size_t p1 = 0;
	std::size_t p2 = 0;

	getEpureLine(file, s, '\n');
	while (file && s.find(CHIPSET_SECTION, 0)
	       == std::string::npos) {
		p1 = getPin(s, 1);
		n1 = getName(s);
		p2 = getPin(s, 2);
		addLinks(std::make_tuple(p2, s, p1),
			 std::make_tuple(p1, n1, p2));
		getEpureLine(file, s, '\n');
	}
	if (s.find(CHIPSET_SECTION, 0) != std::string::npos)
		parseChipsets(file);
}

void Nanotekspice::checkTypeName(const std::string &type,
				 const std::string &name) const
{
	if (!(_facto->checkType(type)))
		throw (SyntaxError(INVALID_TYPE + type + "' !"));
	if (name.find(" ") != std::string::npos)
		throw (SyntaxError(INVALID_NAME + name + " !"));
	if (_types.find(name) != _types.end())
		throw (SyntaxError(SAME_NAME + name + " !"));
}

std::unique_ptr<nts::IComponent> Nanotekspice::createComponent(const std::string &type,
					       const std::string &value)
{
	return _facto->createComponent(type, value);
}

void Nanotekspice::parseChipsets(std::ifstream &file)
{
	std::string s;
	std::string type;

	try {
		getEpureLine(file, s, '\n');
		while (s.find(LINK_SECTION, 0) == std::string::npos) {
			type = s.substr(0, s.find(SPACE, 0));
			s = s.substr(s.find(SPACE, 0) + 1, std::string::npos);
			this->checkTypeName(type, s);
			_types[s] = type;
			if (!getEpureLine(file, s, '\n'))
				break;
		}
		if (s.find(LINK_SECTION, 0) != std::string::npos)
			parseLinks(file);
	} catch (NtsError const& e) {
		throw (e);
	}
}

void Nanotekspice::findParts(const std::string str, std::ifstream &file)
{
	try {
		if (str.find(CHIPSET_SECTION, 0) != std::string::npos)
			parseChipsets(file);
		else if (str.find(LINK_SECTION, 0) != std::string::npos)
			parseLinks(file);
		else
			throw (SyntaxError(MISSING_SECTION));
	} catch (NtsError const& e) {
		throw (e);
	}
}

void Nanotekspice::parseFile(const char *filename)
{
	std::ifstream file(filename);
	std::string buff;
	std::string _filename(filename);
	size_t pos = _filename.find(NTS_EXTENSION);

	if (pos == std::string::npos)
		throw (FileError(INVALID_EXTENSION));
	if (!file.is_open())
		throw (FileError(INVALID_FILE));
	try {
		while (!file.eof())
			if (getEpureLine(file, buff, '\n') && buff != EMPTY)
				this->findParts(buff, file);
	} catch (NtsError const& e) {
		throw (e);
	}
}

void Nanotekspice::assignValue(const std::string cmd)
{
	std::string name = cmd;
	std::string value;

	name = name.erase(name.find("="));
	if (_types.find(name) == _types.end())
		throw(InputError(UNKNOWN_INPUT));
	if (_types[name] != INPUT && _types[name] != CLOCK)
		throw(InputError(NOT_INPUT + name + " !"));
	value = cmd.substr(cmd.find(INPUT_SEPARATOR) + 1);
	if (value != "1" && value != "0")
		throw(InputError(INVALID_VALUE));
	_values[name] = value;
}

void Nanotekspice::checkInputs()
{
	std::map<std::string,
			   std::unique_ptr<nts::IComponent>>::const_iterator
		it = _map.begin();

	while (it != _map.end()) {
		if (_types[it->first] == INPUT
		    && _values.find(it->first) == _values.end())
			throw (InputError(UNDEFINED_INPUT + it->first + "!"));
		it++;
	}
}

void Nanotekspice::checkOutputs()
{
	std::map<std::string,
			   std::unique_ptr<nts::IComponent>>::const_iterator
		it = _map.begin();

	while (it != _map.end()) {
		if (_types[it->first] == OUTPUT) {
			if (_links.find(it->first) == _links.end())
				throw (LinkError(NOT_LINKED
						 + it->first + "!"));
		}
		it++;
	}
}

void Nanotekspice::avoidNormError(std::tuple<std::size_t, std::string,
				  std::size_t> i2, std::string i)
{
	std::size_t p1;
	std::size_t p2;
	std::string otherName;

	std::tie(p1, otherName, p2) = i2;
	if (!_map[i])
		throw (LinkError(UNKNOWN_COMP));
	_map[i]->setLink(p1, *(_map[otherName]), p2);
}

void Nanotekspice::createLinks()
{
	std::unordered_map<std::string,
			   std::list<std::tuple<std::size_t,
						std::string,
						std::size_t>>>::iterator i =
		_links.begin();
	std::list<std::tuple<std::size_t, std::string,
			     std::size_t>>::iterator i2;
	
	while (i != _links.end()) {
		i2 = i->second.begin();
		while (i2 != i->second.end()) {
			avoidNormError(*i2, i->first);
			i2++;
		}
		i++;
	}
}

void Nanotekspice::createComponents()
{
	std::unordered_map<std::string, std::string>::iterator i =
		_types.begin();

	while (i != _types.end()) {
		if (_types[i->first] == INPUT &&
		    _values.find(i->first) == _values.end())
			throw (InputError(UNDEFINED_INPUT));
		_map[i->first] = createComponent(i->second,
						 _values[i->first]);
		i++;
	}
}

void Nanotekspice::createGraph()
{
	try {
		createComponents();
		createLinks();
	} catch (NtsError const& e) {
		throw (e);
	}
}

Nanotekspice::Nanotekspice(int ac, char **av)
{
	int i = 1;

	try {
		_facto = new ComponentFactory;
		this->parseFile(av[i++]);
		while (i < ac)
			this->assignValue(std::string(av[i++]));
		this->createGraph();
		this->checkInputs();
		this->checkOutputs();
	} catch (NtsError const& e) {
		throw (e);
	}
	_cmdList[DISPLAY_CMD] = std::bind(&Nanotekspice::display, this);
	_cmdList[SIMULATE_CMD] = std::bind(&Nanotekspice::simulate, this);
	_cmdList[LOOP_CMD] = std::bind(&Nanotekspice::loop, this);
	_cmdList[DUMP_CMD] = std::bind(&Nanotekspice::dump, this);
}

Nanotekspice::~Nanotekspice()
{
	delete _facto;
}

void Nanotekspice::dump()
{
	std::map<std::string,
			   std::unique_ptr<nts::IComponent>>::iterator
		i = _map.begin();

	while (i != _map.end()) {
		std::cout << (*i).first << LINK_SEPARATOR << SPACE;
		((*i).second)->dump();
		i++;
	}
}

bool handleLoop(int order)
{
	static bool _loop = false;

	if (order == 1)
		_loop = true;
	else if (order == 2)
		_loop = false;
	return (_loop);
}

void sigloop(int n)
{
	(void)n;
	handleLoop(2);
}

void Nanotekspice::simulate()
{
	std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator
		i = _map.begin();

	while (i != _map.end()) {
		if (_types[i->first] == OUTPUT) {
			try {
				(i->second)->compute();
			} catch (NtsError const &e) {
				throw (e);
			}
		}
		i++;
	}
	i = _map.begin();
	while (i != _map.end()) {
		if (_types[i->first] == CLOCK)
			(i->second)->compute(0);
		i++;
	}
}

void Nanotekspice::loop()
{
	sighandler_t old;

	handleLoop(1);
	old = signal(SIGINT, sigloop);
	while (handleLoop(0))
		simulate();
	signal(SIGINT, old);
}

void Nanotekspice::display()
{
	std::map<std::string,
			   std::unique_ptr<nts::IComponent>>::iterator
		i = _map.begin();

	while (i != _map.end()) {
		if (_types[i->first] == OUTPUT) {
			std::cout << i->first;
			(i->second)->dump();
		}
		i++;
	}
}

void Nanotekspice::updateInput(const std::string &cmd)
{
	std::string name = cmd;
	std::string value;

	name = name.erase(name.find(INPUT_SEPARATOR));
	if (_map.find(name) == _map.end())
		throw(InputError(UNKNOWN_INPUT));
	if (_types[name] != INPUT)
		throw(InputError(NOT_INPUT + name + " !"));
	value = cmd.substr(cmd.find("=") + 1);
	if (value != "1" && value != "0")
		throw(InputError(INVALID_VALUE));
	_map[name] = createComponent(_types[name], value);
	createLinks();
}

void Nanotekspice::handleCommand(const std::string &s)
{
	if (_cmdList.find(s) != _cmdList.end())
		_cmdList[s]();
	else {
		if (s.find_first_of(INPUT_SEPARATOR) != std::string::npos)
			updateInput(s);
		else
			std::cout << INVALID << std::endl;
	}
}

void Nanotekspice::launchShell()
{
	std::string s;

	try {
		simulate();
		display();
		std::cout << PROMPT;
		while (getEpureLine(std::cin, s, '\n')) {
			if (s == EXIT_CMD)
				return;
			handleCommand(s);
			std::cout << PROMPT;
		}
	} catch (NtsError const &e) {
		throw(e);
	}
}
