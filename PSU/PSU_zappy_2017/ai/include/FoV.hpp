//
// EPITECH PROJECT, 2018
// zappy
// File description:
// field of view class declaration
//

#pragma once

#include "Inventory.hpp"
#include "Parser.hpp"
#include "Cell.hpp"

#include <map>

#define PlYR_STR "player"
#define FOOD_STR "food"
#define LINE_STR "linemate"
#define MEND_STR "mendiane"
#define THYS_STR "thystame"
#define PHIR_STR "phiras"
#define DER_STR "deraumere"
#define SIB_STR "sibur"

#define COMMAND_START "["
#define COMMAND_END "]"
#define CELL_DELIM ","
#define OBJ_DELIM " "

#define DUMP_CELL_ID(X) std::cout << "Cell n°" << X << ":" << std::endl;
#define DUMP_ENTITY(X, Y) std::cout << "\t" << X << Y << std::endl;

#define PLYR_DUMP " player(s)"
#define FOOD_DUMP " food(s)"
#define MEND_DUMP " mendiane(s)"
#define PHIR_DUMP " phiras"
#define THYS_DUMP " thystane(s)"
#define LINE_DUMP " linemate(s)"
#define DER_DUMP " deraumere(s)"
#define SIB_DUMP " sibur(s)"
#define SEP_DUMP "----------------------"

namespace ai
{
	class FoV
	{
	public:
		FoV(Parser &parser);
		~FoV();

		void upgrade();

		std::pair<short, short> getPath(short cell);
		std::pair<short, short> getPathFromTo(short from, short to);
		std::map<short, Cell*> getVision() const;
		short getNearestItem(Entity type);
		void setVision(std::string rawView);
		void reset();
		void initEntitiesStr();
		void dump();
		std::size_t getNbVillager();

		std::map<short, Cell*> getFoods();
		std::map<short, Cell*> getStuffs();
		bool popRock(Stuff &stuff, short cell);

	private:
		short getMiddle(short line) const;
		std::pair<short, short> getLeft(short line);
		std::pair<short, short> getRight(short line);

		void initLine(short nb);

		void processCell(short cell, std::string content);

	private:
		std::map<std::string, ai::Entity> _eStr;
		std::map<short, Cell*> _cells;
		std::map<short, short> _middles;
		short _level;

		Parser &_parser;

		std::map<short, Cell*> _foods;
		std::map<short, Cell*> _stuffs;
	};
}