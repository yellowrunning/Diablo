#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Door.h"
#include "Loot.h"
#include "ItemFactory.h"
#include "Chest.h"

class Room
{
private:
	std::string myName;
	std::vector<Enemy> myEnemies;
	std::vector<Door*> myDoors;

	std::vector<Loot> myRoomLoot;
	Chest myChest;
	bool myHasChest = false;
	ItemFactory& myItemFactory;

public:
	Room(std::string aName, ItemFactory& aItemFactory);

	void AddEnemy(Enemy anEnemy);
	void AddDoor(Door* aDoor);
	void AddRoomLoot(Loot aLoot) { myRoomLoot.push_back(aLoot); }

	void SetChest(Chest aChest) { myHasChest = true; myChest = aChest; }

	std::string GetName() const;
	bool HasLivingEnemies();

	int Interact(Player& aPlayer, int aCurrentRoomNumber);
};
