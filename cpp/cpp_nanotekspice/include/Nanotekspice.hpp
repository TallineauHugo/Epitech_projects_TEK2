//
// EPITECH PROJECT, 2018
// nano
// File description:
// nanotekspice
//

#pragma once

#include <fstream>
#include <memory>
#include <tuple>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include "IComponent.hpp"
#include "ComponentFactory.hpp"
#include "Exception.hpp"
#include "NanotekspiceMacro.hpp"

class Nanotekspice
{
public:
	Nanotekspice(int ac, char **av);
	~Nanotekspice();

	void launchShell();
	std::unique_ptr<nts::IComponent>
	createComponent(const std::string &type,
			const std::string &value = "");
private:
	std::ifstream &getEpureLine(std::ifstream&, std::string&, char);
	std::istream &getEpureLine(std::istream&, std::string&, char);
	void epurestr(std::string&);
	void replace(std::string&, const std::string, const std::string,
		     std::size_t);
	void removeSpaces(std::string&);

	void parseFile(const char *filename);
	void findParts(const std::string, std::ifstream&);
	void parseChipsets(std::ifstream&);
	void parseLinks(std::ifstream&);
	std::string getName(std::string&);
	std::size_t getPin(std::string&, char);

	void checkTypeName(const std::string&, const std::string&) const;
	void checkInputs();
	void checkOutputs();
	void checkSyntax(const std::string &str) const;
	bool isNumber(const std::string&);

	void createGraph();
	void createComponents();
	void createLinks();
	void avoidNormError(std::tuple<std::size_t, std::string,
			    std::size_t>, std::string);
	void assignValue(const std::string cmd);
	void addLinks(std::tuple<std::size_t, std::string, std::size_t>,
		      std::tuple<std::size_t, std::string, std::size_t>);

	void display(void);
	void simulate(void);
	void loop(void);
	void dump(void);
	void updateInput(const std::string&);
	void handleCommand(const std::string&);

private:
	ComponentFactory* _facto;

	std::unordered_map<std::string, std::function<void(void)>> _cmdList;

	std::map<std::string, std::unique_ptr<nts::IComponent>> _map;
	std::unordered_map<std::string,
			   std::list<std::tuple<std::size_t,
						std::string,
						std::size_t>>> _links;
	std::unordered_map<std::string, std::string> _values;
	std::unordered_map<std::string, std::string> _types;
};
