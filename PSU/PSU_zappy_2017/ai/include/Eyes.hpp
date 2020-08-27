//
// EPITECH PROJECT, 2018
// zappy
// File description:
// eyes
//

#pragma once

#include "FoV.hpp"
#include "Parser.hpp"

#include <string>

namespace ai
{
	namespace Organs
	{
		class Eyes
		{
		public:
			Eyes(Parser &parser);
			~Eyes() = default;

			void look(std::string rawView);
			void upgrade();
			std::pair<short, short> getPath(short cell);
			std::pair<short, short> getPathFromTo(short from, short to);
			short getNearestItem(Entity type);
			std::size_t getNbVillager();

			std::map<short, Cell*> getFoods();
			std::map<short, Cell*> getStuffs();
			bool popRock(Stuff &stuff, short cell);
		private:
			FoV _fov;
		};
	}
}
