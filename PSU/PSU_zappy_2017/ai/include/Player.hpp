//
// EPITECH PROJECT, 2018
// zappy
// File description:
// player
//

#pragma once

#include <memory>

#include "RequestFactory.hpp"
#include "Getter.hpp"
#include "Inventory.hpp"
#include "Stomach.hpp"
#include "Eyes.hpp"
#include "Mouth.hpp"
#include "Brain.hpp"
#include "SignalHandler.hpp"
#include "Direction.hpp"

namespace ai
{
	class Player
	{
	public:
		Player(ai::Parser &parser);
		~Player();

		void run();
	private:
		Parser _parser;
		Inventory _inventory;
		Organs::Stomach _stomach;
		Organs::Eyes _eyes;
		Organs::Mouth _mouth;
		Organs::Brain _brain;

		RequestFactory _requestFactory;
		SignalHandler _signalHandler;

		std::map<short, Cell*> _foods;
		std::map<short, Cell*> _stuffs;
		short _level = 1;
		Direction _dir;

	private:
		void getInfos();
		void upgrade();
		void seek(Entity type);
		void seekNeeded();
		bool hasEnoughFriends();
		void goToCell(short cell);
		void getAllFood();
		short getNearestCell(short pos, std::map<short, Cell*> cells);
		void getAllUsefull();
		std::map<short, Cell*> restrictArea(std::map<short, Cell*> &cells, short from, short to);
		std::map<short, Cell*> keepFoodNeeded();
		void walkAway();
		void turnRight();
		void turnLeft();
		void turnUp();
		void dropItemsForLvlUp();
	};
}
