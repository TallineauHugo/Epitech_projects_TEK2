//
// EPITECH PROJECT, 2018
// zappy
// File description:
// player class implementation
//

#include <iostream>
#include <zconf.h>
#include "Player.hpp"
#include "Exception.hpp"

ai::Player::Player(ai::Parser &parser): _parser(parser), _inventory(_parser),
	_eyes(_parser), _mouth(_parser), _brain(_inventory)
{
	_mouth.init();
	_signalHandler.setupSignalHandler();
	_dir = UP;
}

ai::Player::~Player()
{
}

void ai::Player::getInfos()
{
	std::string inventory;
	std::string vision;

	this->_mouth.sendCommand(*this->_requestFactory.createRequest(GET_INVENTORY));
	while (!this->_mouth.getInventory(inventory));
	this->_mouth.sendCommand(*this->_requestFactory.createRequest(LOOK));
	while (!this->_mouth.getVision(vision));
	this->_eyes.look(vision);
	this->_inventory.updateInventory(inventory);
	this->_stomach.updateFood(_inventory.getNbStuff(FOOD));
	this->_foods = this->_eyes.getFoods();
	this->_stuffs = this->_eyes.getStuffs();
}

void ai::Player::run()
{
	std::string cmd;
	
	while (!this->_signalHandler.gotExitSignal()) {
		this->getInfos();
		this->_foods = this->keepFoodNeeded();
		if (this->_stomach.isHungry()) {
			std::cout << "HUNGRY\n";
			this->getAllFood();
		}
		else if (this->_brain.canElevate()) {
			std::cout << "CAN ELEVATE\n";
			if (this->hasEnoughFriends())
				this->upgrade();
		}
		else if (this->_stuffs.size() != 0) {
			std::cout << "GET ALL USEFULL\n";
			this->getAllUsefull();
		}
		else if (this->_foods.size() != 0) {
			std::cout << "GET ALL FOOD\n";
			this->getAllFood();
		}
		else
			walkAway();
		while (_mouth.queueIsEmpty() == false) {
			_mouth.getCommand(cmd);			              
		}
	}
	this->_mouth.sendCommand(*this->_requestFactory.createRequest(DEATH));
}

void ai::Player::dropItemsForLvlUp()
{
	std::map<ai::Entity, int> map = _brain.getRecquiredItemsForLvlUp();
	auto it = map.begin();

	int i = 0;

	while (it != map.end()) {
		if (it->first != VILLAGER && it->first != E_FOOD) {
			while (i < it->second) {
				_mouth.sendCommand(
					*(_requestFactory.createRequest(
						  DROP_ITEM,
						  _brain.convertEntityToStuff(it->first))));
				i++;
			}			                
		}
		i = 0;
		it++;		        
	}	
}

std::map<short, ai::Cell*> ai::Player::keepFoodNeeded()
{
	std::map<short, ai::Cell*>res;
	auto it = this->_foods.begin();

	while (it != this->_foods.end()) {
		if (it->second->getNbEntity(E_FOOD) > 0)
			res[it->first] = it->second;
		it++;
	}
	return res;
}

short ai::Player::getNearestCell(short pos, std::map<short, Cell*> cells)
{
	short dist = MAX_DIST;
	int tmp;
	short nearest = -1;
	auto it = cells.begin();

	while (it != cells.end()) {
		std::pair<short, short> tmpPath(this->_eyes.getPathFromTo(pos, it->first));

		tmp = std::abs(tmpPath.first) + std::abs(tmpPath.second);
		if (tmp <= dist) {
			dist = tmp;
			nearest = it->first;
		}
		it++;
	}
	return nearest;
}

void ai::Player::getAllFood()
{
	std::size_t i;
	short cell = 0;
	short nearest;
	unsigned short checked = 0;
	std::size_t initialNumber;

	std::cout << "Get all food:\n";
	std::cout << "_foods.size(): " << _foods.size() << std::endl;
	if (_foods.size() == 0) {
		walkAway();
		return;
	}
	while (checked < this->_foods.size()) {
		std::cout << "while...\n";
		i = 0;
		nearest = this->getNearestCell(cell, this->_foods);
		std::cout << "nearest food: " << nearest << std::endl;
		if (nearest < 0) {
			std::cout << "BITE\n";
			walkAway();
			std::cout << "nearest = -1: A GERER\n";
			return;
		}
		this->goToCell(nearest);
		cell = nearest;
		initialNumber = this->_foods[cell]->getNbEntity(E_FOOD);
		while (i < initialNumber) {
			this->_mouth.sendCommand(*this->_requestFactory.createRequest(TAKE_ITEM, FOOD));
			this->_foods[cell]->popFood();
			i++;
		}
		checked++;
	}
}

void ai::Player::getAllUsefull()
{
	Stuff stuff;
	std::size_t i = 0;
	short cell = 0;
	short nearest;
	short food;
	unsigned short checked = 0;

	nearest = this->getNearestCell(cell, this->_stuffs);
	std::cout << "BOUCLE INF: nearest = " << nearest << std::endl;
	std::cout << "_foos.size(): " << _foods.size() << std::endl;
	while (checked < this->_foods.size()) {
		this->_foods = this->restrictArea(this->_foods, cell, nearest);
		
		food = this->getNearestCell(cell, this->_foods);
		std::cout << "food restricted: " << food << std::endl;
		if (food < 0) {
			walkAway();
			std::cout << "nearest = -1: A GERER\n";
			return;
		}
		this->goToCell(food);
		cell = food;
		std::cout << "On getNbEntity sur la cell " << cell << std::endl;
		if (this->_foods.find(cell) != _foods.end()) {
			std::cout << "On a trouvé la cellule\n";
			while (i < this->_foods[cell]->getNbEntity(E_FOOD)) {
				std::cout << "LOOT FOOD\n";
				this->_mouth.sendCommand(*this->_requestFactory.createRequest(TAKE_ITEM, FOOD));
				i++;
			}
			i = 0;
		}
		checked++;
	}
	nearest = this->getNearestCell(cell, this->_stuffs);
	std::cout << "Pas trouvé de food, nearest = " << nearest << std::endl;
	if (nearest < 0) {
		walkAway();
		std::cout << "ON GLANDE\n";
		return;
	}
	goToCell(nearest);
	cell = nearest;
	stuff = FOOD;
	std::cout << "On get stuff dans la cell " << cell << std::endl;
	if (_foods.find(cell) == _foods.end()) {
		walkAway();
		return;
	}
	while (this->_foods[cell]->popRock(stuff)) {
		std::cout << "pop rock\n";
		this->_mouth.sendCommand((*this->_requestFactory.createRequest(TAKE_ITEM, stuff)));
	}
}

std::map<short, ai::Cell*> ai::Player::restrictArea(std::map<short, Cell *> &cells, short from, short to)
{
	std::map<short, ai::Cell*> res;
	auto it = cells.begin();
	bool valid;

	while (it != cells.end()) {
		std::pair<short, short> fromPath(this->_eyes.getPath(from));
		std::pair<short, short> toPath(this->_eyes.getPath(to));
		std::pair<short, short> foodPath(this->_eyes.getPath(it->first));

		valid = true;
		if (fromPath.second <= toPath.second && !(foodPath.second >= fromPath.second && foodPath.second <= toPath.second))
			valid = false;
		else if (fromPath.second >= toPath.second && !(foodPath.second <= fromPath.second && foodPath.second >= toPath.second))
			valid = false;
		if (fromPath.first <= toPath.first && !(foodPath.first >= fromPath.first && foodPath.first <= toPath.first))
			valid = false;
		else if (fromPath.first >= toPath.first && !(foodPath.first <= fromPath.first && foodPath.first >= toPath.first))
			valid = false;
		if (valid)
			res[it->first] = it->second;
		it++;
	}
	return res;
}

void ai::Player::upgrade()
{
	this->dropItemsForLvlUp();
	this->_mouth.sendCommand(*(_requestFactory.createRequest(INCANTATION)));
	this->_mouth.addRequest("Incantation");
	if (this->_mouth.tryLvlUp()) {
		this->_eyes.upgrade();
		this->_brain.upgrade();
		this->_level++;
		return;
	}
}

void ai::Player::seek(Entity type)
{
	short nearest = this->_eyes.getNearestItem(type);

	if (nearest == -1)
		this->_mouth.sendCommand(*this->_requestFactory.createRequest(MOVE_FORWARD));
	else {
		this->goToCell(nearest);
		this->_mouth.sendCommand(
			*this->_requestFactory.createRequest(TAKE_ITEM,
				this->_brain.convertEntityToStuff(type)));
	}
}

void ai::Player::seekNeeded()
{
	std::map<Entity, int> recquired = this->_brain.getRecquiredItems();
	auto it = recquired.begin();
	short cell;

	while (it != recquired.end()) {
		if (it->second > 0 && it->first != VILLAGER) {
			cell = this->_eyes.getNearestItem(it->first);
			if (cell != -1) {
				goToCell(cell);
				this->_mouth.sendCommand(
					*this->_requestFactory.createRequest(TAKE_ITEM,
						this->_brain.convertEntityToStuff(it->first)));
				return;
			}
			else {
				walkAway();
				std::cout << "ON GLANDE\n";
			}
		}
		it++;
	}
	it = recquired.begin();
	while (it != recquired.end()) {
		if (it->second > -2 && it->first != VILLAGER) {
			cell = this->_eyes.getNearestItem(it->first);
			if (cell != -1) {
				goToCell(cell);
				this->_mouth.sendCommand(
					*this->_requestFactory.createRequest(TAKE_ITEM,
						this->_brain.convertEntityToStuff(it->first)));
				return;
			}
			else {
				walkAway();
				std::cout << "ON GLANDE\n";
			}
		}
		it++;
	}
	this->_mouth.sendCommand(*this->_requestFactory.createRequest(MOVE_FORWARD));
}

bool ai::Player::hasEnoughFriends()
{
	int recquired = this->_brain.getRecquiredItems()[VILLAGER];

	return recquired <= (int)this->_eyes.getNbVillager();
}

void ai::Player::goToCell(short cell)
{
	std::pair<short, short> path(this->_eyes.getPath(cell));
	short move = 0;

	std::cout << "Go to " << path.first << ", " << path.second << std::endl;
	while (move < path.first) {
		this->_mouth.sendCommand(
			*this->_requestFactory.createRequest(MOVE_FORWARD));
		move++;
	}
	move = 0;
	if (path.second < 0)
		this->turnLeft();
	else if (path.second > 0)
		this->turnRight();
	while (move != path.second) {
		move = path.second < 0 ? move - 1 : move + 1;
		this->_mouth.sendCommand(*this->_requestFactory.createRequest(MOVE_FORWARD));
	}
	this->turnUp();
}

void ai::Player::walkAway()
{
	std::cout << "WALKAWAY" << std::endl;
	short i = 0;

	while (i++ < this->_level)
		this->_mouth.sendCommand(*this->_requestFactory.createRequest(MOVE_FORWARD));
}

void ai::Player::turnRight()
{
	if (this->_dir == UP)
		this->_dir = RIGHT;
	else if (this->_dir == RIGHT)
		this->_dir = DOWN;
	else if (this->_dir == DOWN)
		this->_dir = LEFT;
	else if (this->_dir == LEFT)
		this->_dir = UP;
	this->_mouth.sendCommand(*this->_requestFactory.createRequest(TURN_RIGHT));
}

void ai::Player::turnLeft()
{
	if (this->_dir == UP)
		this->_dir = LEFT;
	else if (this->_dir == LEFT)
		this->_dir = DOWN;
	else if (this->_dir == DOWN)
		this->_dir = RIGHT;
	else if (this->_dir == RIGHT)
		this->_dir = UP;
	this->_mouth.sendCommand(*this->_requestFactory.createRequest(TURN_LEFT));
}

void ai::Player::turnUp()
{
	if (this->_dir == RIGHT)
		this->turnLeft();
	else if (this->_dir == LEFT)
		this->turnRight();
	else if (this->_dir == DOWN) {
		this->turnLeft();
		this->turnLeft();
	}
}
