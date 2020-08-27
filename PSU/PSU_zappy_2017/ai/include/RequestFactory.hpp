//
// EPITECH PROJECT, 2018
// zappy
// File description:
// request factory
//

#pragma once

#include <memory>
#include <map>
#include "Request.hpp"
#include "Action.hpp"
#include "Stuff.hpp"

namespace ai
{
	class RequestFactory
	{
	public:
		RequestFactory();
		~RequestFactory();
	public:
		std::unique_ptr<Request> createRequest(std::string str);
		std::unique_ptr<Request> createRequest(Action action);
		std::unique_ptr<Request> createRequest(Action action,
			Stuff item);
	private:
		void initFactory();
		void initActionToCommand();
		void initActionToDurationTime();
		void initStuffToString();
	private:
		std::map<Action, std::string> _actionToCommand;
		std::map<Action, std::size_t> _actionToDurationTime;
		std::map<Stuff, std::string> _stuffToString;
	};
}
