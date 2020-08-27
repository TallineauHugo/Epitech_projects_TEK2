//
// EPITECH PROJECT, 2018
// zappy
// File description:
// parser
//

#include "Parser.hpp"
#include "Exception.hpp"

ai::Parser::Parser() : _portOK(false), _teamOK(false)
{
	_port = 4242;
	_map["-p"] = std::bind(&ai::Parser::setPort, this,
		std::placeholders::_1);
	_map["-n"] = std::bind(&ai::Parser::setTeam, this,
		std::placeholders::_1);
	_map["-h"] = std::bind(&ai::Parser::setMachine, this,
		std::placeholders::_1);
}

ai::Parser::~Parser()
{
}
#include <iostream>
void ai::Parser::loadArguments(int ac, char **av)
{
	int i = 0;
	std::function<void(std::string)> ptr;

	if (ac < 5)
		throw ClientError("./zappy_ai -p port -n name");
	while (i < ac) {
		if (_map.find(av[i]) != _map.end() &&
			i + 1 < ac &&
			_map.find(av[i + 1]) == _map.end()) {
			ptr = _map[av[i]];
			i++;
			ptr(av[i]);
		}
		i++;
	}
	if (_portOK == false || _teamOK == false) {
		throw ClientError("./zappy_ai -p port -n name");
	}
}

std::size_t ai::Parser::getPort()
{
	return _port;
}

std::string ai::Parser::getTeam()
{
	return _team;
}

void ai::Parser::setPort(std::string str)
{
	_port = atoi(str.c_str());
	_portOK = true;
}

void ai::Parser::setTeam(std::string str)
{
	_team = str;
	_teamOK = true;
}

void ai::Parser::setMachine(std::string str)
{
	(void)str;
}

void ai::Parser::removeDoubleSpaces(std::string &str)
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

void ai::Parser::replace(std::string &str, const std::string toReplace,
	const std::string by)
{
	size_t index = 0;

        while (1) {
                index = str.find(toReplace, index);
                if (index == std::string::npos)
			break;
                str.replace(index, toReplace.size(), by);
        }
}

void ai::Parser::epurestr(std::string &str)
{
	replace(str, TAB, SPACE);
	replace(str, RETURN, EMPTY);
	removeDoubleSpaces(str);
}

std::list<std::string> ai::Parser::getToken(std::string &from,
	const std::string separators)
{
	std::size_t fromPos = 0;
	std::size_t toPos = 0;
	std::list<std::string> tokens;

	toPos = from.find_first_of(separators);
	while (fromPos != std::string::npos) {
		tokens.push_back(from.substr(fromPos, (toPos - fromPos)));
		fromPos = toPos;
		if (fromPos != std::string::npos &&
			separators.find(from[fromPos]) != std::string::npos)
			fromPos += 1;
		if (fromPos != std::string::npos && from[fromPos] == ' ')
			fromPos += 1;
		toPos = from.find_first_of(separators, fromPos);
	}
	return tokens;
}
