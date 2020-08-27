//
// EPITECH PROJECT, 2018
// zappy
// File description:
// command manager
//

#include <string>
#include "CommandManager.hpp"
#include "Exception.hpp"

ai::CommandManager::CommandManager()
{
	_inventory = "";
	_vision = "";
	_text = "";
	_elevation = "";
}

ai::CommandManager::~CommandManager()
{
}

bool ai::CommandManager::addRequest(std::string str)
{
	if (_queue.size() < 10) {
		_queue.push(*(_facto.createRequest(str)));
		return true;
	}
	return false;
}

bool ai::CommandManager::addRequest(Request request)
{
	if (_queue.size() < 10) {
		_queue.push(request);
		return true;
	}
	return false;
}

bool ai::CommandManager::queueIsEmpty()
{
	return _queue.empty();
}

#include <iostream>
void ai::CommandManager::addResponse(std::string &cmd)
{
	if (!cmd.compare(0, 7, "WELCOME"))
		return;

	if (!cmd.compare(0, 4, "dead"))
		throw ClientError("dead");
	else if (!cmd.compare(0, 2, "ko")) {
		Request *request = _queue.pop();
		if (!request)
			return;
		if (request->getCommand() == "Incantation")
			_elevation = "ko";
	}
	else if (!cmd.compare(0, 2, "ok")) {
		_queue.pop();
	}
	else if (cmd.front() == '[' && cmd.back() == ']') {
		if (cmd.find_first_of("0123456789") != std::string::npos && _inventory == "") {
			/*Request *request = _queue.pop();
			if (!request) {
				throw ClientError(
					"Queue vide, que faire de la réponse ?");
			}*/
			_inventory = _queue.deleteInventory(cmd);
			//_inventory = cmd;
		}
			else if (cmd.find_first_of("0123456789") == std::string::npos && _vision == "") {
			/*Request *request = _queue.pop();
			if (!request)
				throw ClientError("Queue vide, que faire de la réponse ?"); */
			_vision = _queue.deleteVision(cmd);
			//_vision = cmd;
		}

	}
	else if (!cmd.compare(0, std::string((ELEVATION_START)).size(), ELEVATION_START)) {
		Request *request = _queue.pop();
		if (!request)
			return;
		_elevation = ELEVATION_START;
	}
	else if (!cmd.compare(0, std::string((ELEVATION_DONE)).size(), ELEVATION_DONE)) {
		Request *request = _queue.pop();
		if (!request)
			return;
		_elevation = ELEVATION_DONE;
	}
	else
		_queue.pop();
	//else if (sound) {
	//	_text = _queue.getSound(cmd);
	//}
}

std::string ai::CommandManager::getVision()
{
	std::string tmp(_vision);

	_vision = "";
	return tmp;
}

std::string ai::CommandManager::getInventory()
{
	std::string tmp(_inventory);

	_inventory = "";
	return tmp;
}

std::string ai::CommandManager::getElevation()
{
	std::string tmp(_elevation);

	_elevation = "";
	return tmp;
}
