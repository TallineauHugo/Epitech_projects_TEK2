//
// EPITECH PROJECT, 2018
// zappy
// File description:
// request
//

#pragma once

#include <string>

namespace ai
{	
	class Request
	{
	public:
		Request(std::string command, std::size_t durationTime);
		Request(std::string command);
		~Request();
	public:
		std::string getCommand() const;
		std::size_t getDurationTime() const;
	private:
		std::string _command;
		std::size_t _durationTime;	       
	};
}
