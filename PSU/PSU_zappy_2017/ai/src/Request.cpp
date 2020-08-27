//
// EPITECH PROJECT, 2018
// zappy
// File description:
// request
//

#include "Request.hpp"

#include <utility>

ai::Request::Request(std::string command, std::size_t durationTime) :
_command(std::move(command)), _durationTime(durationTime)
{
}

ai::Request::Request(std::string command) : _command(std::move(command)), _durationTime(0)
{
}

ai::Request::~Request()
{
}

std::string ai::Request::getCommand() const
{
	return _command;
}

std::size_t ai::Request::getDurationTime() const
{
	return _durationTime;
}
