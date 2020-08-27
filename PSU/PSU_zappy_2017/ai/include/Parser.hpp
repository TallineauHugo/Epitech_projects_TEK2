//
// EPITECH PROJECT, 2018
// zappy
// File description:
// parser class declaration
//

#pragma once

#include <string>
#include <list>
#include <functional>
#include <map>

#define TAB "\t"
#define SPACE " "
#define RETURN "\n"
#define EMPTY ""

namespace ai
{
	class Parser
	{
	public:
		Parser();
		~Parser();
	public:
		void epurestr(std::string &str);
		void replace(std::string &str, const std::string toReplace,
			const std::string by);
		void loadArguments(int ac, char **av);
		std::list<std::string> getToken(std::string &from,
			const std::string separators);
		std::size_t getPort();
		std::string getTeam();
	private:
		void removeDoubleSpaces(std::string &str);
		void setPort(std::string str);
		void setTeam(std::string str);
		void setMachine(std::string str);
	private:
		std::size_t _port;
		std::string _team;
		bool _portOK;
		bool _teamOK;
		std::map<std::string, std::function<void(std::string)>> _map;
	};
}