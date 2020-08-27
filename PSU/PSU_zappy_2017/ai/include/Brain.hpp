//
// EPITECH PROJECT, 2018
// zappy
// File description:
// brain
//

#pragma once

#include <map>

#include "Inventory.hpp"
#include "Entity.hpp"
#include "Stuff.hpp"

#define MAX_DIST 16

namespace ai
{
	namespace Organs
	{
		class Brain
		{
		public:
			Brain(Inventory &inv);
			~Brain();
		public:
			bool canElevate();
			std::map<Entity, int> getRecquiredItems();
			std::map<Entity, int> getRecquiredItemsForLvlUp();
			void upgrade();
			Stuff convertEntityToStuff(Entity entity);
		private:
			Inventory &_inv;
			std::map<int, std::map<Entity, int>> _recquired;
			int _lvl;
			std::map<Entity, Stuff> _eToStuff;
		private:
			void initEntityToStuff();
		};
	}
}
