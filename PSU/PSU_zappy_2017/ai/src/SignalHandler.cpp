//
// EPITECH PROJECT, 2018
// zappy
// File description:
// signal handler class implementation
//

#include <csignal>

#include "SignalHandler.hpp"

bool ai::SignalHandler::_exitSignal = false;

bool ai::SignalHandler::gotExitSignal()
{
	return _exitSignal;
}

void ai::SignalHandler::setupSignalHandler()
{
	signal(SIGINT, SignalHandler::exitSignalHandler);
}

void ai::SignalHandler::exitSignalHandler(int ignored)
{
	_exitSignal = true;
	(void)ignored;
}
