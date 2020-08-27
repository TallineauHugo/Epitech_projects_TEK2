//
// EPITECH PROJECT, 2018
// zappy
// File description:
// stomach
//

#pragma once

#include <string>

#define MIN_FOOD_BEFORE_HUNGRY 8

namespace ai
{
	namespace Organs {
		class Stomach
		{
		public:
			Stomach();
			~Stomach();
		public:
			void updateFood(std::size_t newAmount);
			bool isHungry() const;
		private:
			std::size_t _food;
			bool _hungry;
		};
	}
}
