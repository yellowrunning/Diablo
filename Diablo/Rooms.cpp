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
	for (int i = 0; i < enemies.size(); ++i)
	{
		if (enemies[i].IsAlive()) return true;
	}
	return false;
}

int Room::Interact(Player& player, int currentRoomNumber)
{
	std::cout << "\n====================================\n";
	std::cout << "You are in: " << name << "\n";
	std::cout << "====================================\n";

	if (HasLivingEnemies())
	{
		Combat::Fight(player, enemies);
		if (!player.IsAlive()) return currentRoomNumber;
	}

	system("cls");
	std::cout << "====================================\n";
	std::cout << "You are in: " << name << "\n";
	std::cout << "====================================\n\n";

	std::cout << "[1] View your stats\n";
	for (int i = 0; i < doors.size(); ++i)
	{
		int dest = doors[i]->GetDestination(currentRoomNumber);
		std::cout << "[" << i + 2 << "] Go to door leading to room " << dest;
		if (doors[i]->IsLocked())
		{
			std::cout << " (LOCKED)";
		}
		std::cout << "\n";
	}
	std::cout << "Choose action: ";
	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		system("cls");
		player.ShowStats();
		system("pause");
		return currentRoomNumber;
	}

	int doorChoice = choice - 2;
	if (doorChoice >= 0 && doorChoice < doors.size())
	{
		Door* selectedDoor = doors[doorChoice];

		if (selectedDoor->IsLocked())
		{
			system("cls");
			std::cout << "The door is locked! Choose how to open it:\n";
			std::cout << "[1] Pick the lock (Uses Agility)\n";
			std::cout << "[2] Break down the door (Uses Strength)\n";
			std::cout << "[3] Go back\n";
			std::cout << "Choice: ";
			int lockChoice;
			std::cin >> lockChoice;

			if (lockChoice == 1 || lockChoice == 2)
			{
				bool success = selectedDoor->AttemptUnlock(player, lockChoice);
				system("pause");

				if (!success)
				{
					return currentRoomNumber;
				}
			}
		}
		return selectedDoor->GetDestination(currentRoomNumber);
	}
	return currentRoomNumber;
}
