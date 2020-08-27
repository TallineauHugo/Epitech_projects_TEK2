//
// EPITECH PROJECT, 2018
// zappy
// File description:
// queue
//

#pragma once

#include <list>
#include <map>
#include "Action.hpp"
#include "RequestFactory.hpp"

namespace ai {
	class Queue
	{
	public:
		Queue();
		~Queue();
	public:
		std::string deleteInventory(std::string &cmd);
		std::string deleteVision(std::string &cmd);
		std::string getSound(std::string &cmd);
		void addRequest(Request request);
		bool empty();

		Request *pop();
		void push(Request request);

		int size();
	private:
		void dump();
	private:
		std::list<Request> _queue;
		//std::list<Request>
		std::map<Action, std::string> _actionToCommand;
		RequestFactory _facto;
	};
}