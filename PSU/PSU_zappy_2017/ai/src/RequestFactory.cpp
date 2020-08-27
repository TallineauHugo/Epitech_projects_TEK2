//
// EPITECH PROJECT, 2018
// zappy
// File description:
// request factory
//

#include "RequestFactory.hpp"

ai::RequestFactory::RequestFactory()
{
	initFactory();
}

ai::RequestFactory::~RequestFactory()
{
}

void ai::RequestFactory::initActionToCommand()
{
	_actionToCommand[MOVE_FORWARD] = "Forward\n";
	_actionToCommand[TURN_RIGHT] = "Right\n";
	_actionToCommand[TURN_LEFT] = "Left\n";

	_actionToCommand[LOOK] = "Look\n";
	_actionToCommand[GET_INVENTORY] = "Inventory\n";
	_actionToCommand[BROADCAST] = "Broadcast \n";

	_actionToCommand[UNUSED_SLOT] = "Connect_nbr\n";
	_actionToCommand[FORK] = "Fork\n";
	_actionToCommand[EJECT] = "Eject\n";
	_actionToCommand[DEATH] = "dead\n";

	_actionToCommand[TAKE_ITEM] = "Take ";
	_actionToCommand[DROP_ITEM] = "Set ";
	_actionToCommand[INCANTATION] = "Incantation\n";
}

void ai::RequestFactory::initActionToDurationTime()
{
	_actionToDurationTime[MOVE_FORWARD] = 7;
	_actionToDurationTime[TURN_RIGHT] = 7;
	_actionToDurationTime[TURN_LEFT] = 7;

	_actionToDurationTime[LOOK] = 7;
	_actionToDurationTime[GET_INVENTORY] = 1;
	_actionToDurationTime[BROADCAST] = 7;

	_actionToDurationTime[UNUSED_SLOT] = 0;
	_actionToDurationTime[FORK] = 42;
	_actionToDurationTime[EJECT] = 7;
	_actionToDurationTime[DEATH] = 0;

	_actionToDurationTime[TAKE_ITEM] = 7;
	_actionToDurationTime[DROP_ITEM] = 7;
	_actionToDurationTime[INCANTATION] = 300;
}

void ai::RequestFactory::initStuffToString()
{
	_stuffToString[ai::Stuff::FOOD] = "food\n";
	_stuffToString[ai::Stuff::LINEMATE] = "linemate\n";
	_stuffToString[ai::Stuff::DERAUMERE] = "deraumere\n";
	_stuffToString[ai::Stuff::SIBUR] = "sibur\n";
	_stuffToString[ai::Stuff::MENDIANE] = "mendiane\n";
	_stuffToString[ai::Stuff::PHIRAS] = "phiras\n";
	_stuffToString[ai::Stuff::THYSTAME] = "thystame\n";
}

void ai::RequestFactory::initFactory()
{
	initActionToCommand();
	initActionToDurationTime();
	initStuffToString();
}

std::unique_ptr<ai::Request> ai::RequestFactory::createRequest(std::string str)
{
	std::unique_ptr<ai::Request> request(new Request(str));

	return request;
}

std::unique_ptr<ai::Request> ai::RequestFactory::createRequest(
	ai::Action action
)
{
	std::unique_ptr<ai::Request> request(new Request(_actionToCommand[action],
		_actionToDurationTime[action]));

	return request;
}

std::unique_ptr<ai::Request> ai::RequestFactory::createRequest(
	ai::Action action, ai::Stuff item
)
{
	std::unique_ptr<ai::Request> request(new
		Request(_actionToCommand[action] + _stuffToString[item],
		_actionToDurationTime[action]));

	return request;
}
