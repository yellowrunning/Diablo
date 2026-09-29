#include "Rooms.h"
#include "Combat.h"
#include <iostream>

Room::Room(std::string aName)
{
	name = aName;
}

void Room::AddEnemy(Enemy anEnemy)
{
	enemies.push_back(anEnemy);
}

void Room::AddDoor(Door* aDoor)
{
	doors.push_back(aDoor);
}

std::string Room::GetName() const
{
	return name;
}

bool Room::HasLivingEnemies()
{
	for (size_t i = 0; i < enemies.size(); ++i)
	{
		if (enemies[i].IsAlive()) return true;
	}
	return false;
}

int Room::Interact(Player& player, int currentRoomIndex)
{
	std::cout << "\n====================================\n";
	std::cout << "You are in: " << name << "\n";
	std::cout << "====================================\n";

	if (HasLivingEnemies())
	{
		Combat::Fight(player, enemies);
		if (!player.IsAlive()) return currentRoomIndex;
	}

	std::cout << "[1] View your stats\n";
	for (size_t i = 0; i < doors.size(); ++i)
	{
		int dest = doors[i]->GetDestination(currentRoomIndex);
		std::cout << "[" << i + 2 << "] Go to door leading to room " << dest << "\n";
	}
	std::cout << "Choose action: ";
	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		player.ShowStats();
		system("pause");
		return currentRoomIndex;
	}

	size_t doorChoice = choice - 2;
	if (doorChoice >= 0 && doorChoice < doors.size())
	{
		return doors[doorChoice]->GetDestination(currentRoomIndex);
	}

	return currentRoomIndex;
}
