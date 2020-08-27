//
// EPITECH PROJECT, 2018
// zappy
// File description:
// cell class declaration
//

#pragma once

#include "Entity.hpp"
#include "Stuff.hpp"

#include <map>

namespace ai
{
	class Cell
	{
	public:
		Cell();
		~Cell();

		void reset();
		void addEntity(Entity type);

		std::size_t getNbEntity(Entity type);

		bool popRock(Stuff &stuff);
		void popFood();

	private:
		std::map<Entity, std::size_t> _entities;
	};
}