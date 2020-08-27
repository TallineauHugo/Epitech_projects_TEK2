//
// EPITECH PROJECT, 2018
// zappy
// File description:
// command manager
//

#pragma once

#include <string>
#include "Queue.hpp"

#define ELEVATION_START "Elevation underway"
#define ELEVATION_DONE "Current level:"

namespace ai {
	class CommandManager
	{
	public:
		CommandManager();
		~CommandManager();
	public:
		std::string getVision();
		std::string getInventory();
		std::string getElevation();

		//void sort(std::string &cmd);
		void addResponse(std::string &cmd);
		bool addRequest(Request request);
		bool addRequest(std::string str);
		bool queueIsEmpty();

	private:
	private:
		RequestFactory _facto;
		Queue _queue;
		std::string _inventory;
		std::string _vision;
		std::string _text;
		std::string _elevation;
	};
}