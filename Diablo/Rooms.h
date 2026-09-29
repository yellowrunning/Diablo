#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Door.h"

class Room
{
private:
	std::string name;
	std::vector<Enemy> enemies;
	std::vector<Door*> doors;

public:
	Room(std::string aName);

	void AddEnemy(Enemy anEnemy);
	void AddDoor(Door* aDoor);
	std::string GetName() const;
	bool HasLivingEnemies();

	int Interact(Player& player, int currentRoomNumber);
};