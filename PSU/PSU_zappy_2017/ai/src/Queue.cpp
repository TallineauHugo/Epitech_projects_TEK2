//
// EPITECH PROJECT, 2018
// zappy
// File description:
// queue
//

#include "Action.hpp"
#include "Queue.hpp"

ai::Queue::Queue()
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

ai::Queue::~Queue()
{
}
#include <iostream>
std::string ai::Queue::deleteInventory(std::string &cmd)
{
	auto it = _queue.begin();
	std::string str;
	std::string tmp;
	int i = 0;

	while (it != _queue.end()) {
		str = it->getCommand();
		tmp = _actionToCommand[GET_INVENTORY];
		if (!str.compare(0, tmp.size(), tmp)) {
			_queue.erase(it);
			dump();
			return cmd;
		}
		it++;
		i++;
	}
	return "";
}

int ai::Queue::size()
{
	return _queue.size();
}

std::string ai::Queue::deleteVision(std::string &cmd)
{
	auto it = _queue.begin();
	std::string str;
	std::string tmp;
	int i = 0;

	while (it != _queue.end()) {
		str = it->getCommand();
		tmp = _actionToCommand[LOOK];
		if (!str.compare(0, tmp.size(), tmp)) {
			_queue.erase(it);
			dump();
			return cmd;
		}
		it++;
		i++;
	}
	return "";
}

void ai::Queue::addRequest(Request request)
{
	_queue.push_back(request);
}

void ai::Queue::dump()
{
	auto i = _queue.begin();

	std::cout << "[QUEUE]:\n";
	while (i != _queue.end()) {
		std::cout << "-> " << i->getCommand() << std::endl;
		i++;
	}
	std::cout << "---------------------\n";
}

ai::Request *ai::Queue::pop()
{
	if (_queue.empty())
		return nullptr;
	Request *request = &_queue.front();

	_queue.pop_front();
	dump();
	return request;
}

std::string ai::Queue::getSound(std::string &cmd)
{
	auto it = _queue.begin();
	std::string str;
	std::string tmp;

	while (it != _queue.end()) {
		str = it->getCommand();
		tmp = _actionToCommand[BROADCAST];
		if (!str.compare(0, tmp.size(), tmp)) {
			_queue.erase(it);
			return cmd;
		}
		it++;
	}
	return "";
}

bool ai::Queue::empty()
{
	return _queue.empty();
}

void ai::Queue::push(ai::Request request)
{
	_queue.push_back(request);
	dump();
}
