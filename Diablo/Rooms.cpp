#include "Rooms.h"
#include "Combat.h"
#include <iostream>
#include <random>
#include <string>

Room::Room(std::string aName)
{
	myName = aName;
}

void Room::AddEnemy(Enemy anEnemy)
{
	myEnemies.push_back(anEnemy);
}

void Room::AddDoor(Door* aDoor)
{
	myDoors.push_back(aDoor);
}

std::string Room::GetName() const
{
	return myName;
}

bool Room::HasLivingEnemies()
{
	for (int i = 0; i < myEnemies.size(); ++i)
	{
		if (myEnemies[i].IsAlive()) return true;
	}
	return false;
}

int Room::Interact(Player& aPlayer, int aCurrentRoomNumber)
{
	if (HasLivingEnemies())
	{
		Combat::Fight(aPlayer, myEnemies);
		if (!aPlayer.IsAlive()) return aCurrentRoomNumber;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dropChance(1, 10);
		if (dropChance(gen) <= 3)
		{
			std::cout << "\nThe defeated enemy dropped something on the floor!\n";
			myRoomLoot.push_back(Loot::CreateItem(5));
			system("pause");
		}
	}

	system("cls");
	std::cout << "====================================\n";
	std::cout << "You are in: " << myName << "\n";
	std::cout << "====================================\n\n";
	std::cout << "Your HP: " << aPlayer.GetHealth() << " / " << aPlayer.GetMaxHealth() << "\n";

	std::cout << "[1] View your stats & inventory\n";
	std::cout << "[2] Inspect the floor (Look for Items/Spells)\n";

	int menuIndex = 3;
	int chestOption = 0;
	if (myHasChest)
	{
		chestOption = menuIndex;
		std::cout << "[" << menuIndex << "] Open the Chest in the room\n";
		menuIndex++;
	}

	int firstDoorMenuNum = menuIndex;
	for (int i = 0; i < myDoors.size(); ++i)
	{
		int dest = myDoors[i]->GetDestination(aCurrentRoomNumber);
		std::cout << "[" << menuIndex << "] Go to door leading to room " << dest;
		if (myDoors[i]->IsLocked()) std::cout << " (LOCKED)";
		std::cout << "\n";
		menuIndex++;
	}

	std::cout << "Choose action: ";
	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		system("cls");
		aPlayer.ShowStats();
		system("pause");
		return aCurrentRoomNumber;
	}

	if (choice == 2)
	{
		system("cls");
		std::cout << "=== SEARCHING THE FLOOR ===\n";
		if (myRoomLoot.empty())
		{
			std::cout << "The floor is bare. Nothing here.\n";
		}
		else
		{
			Loot found = myRoomLoot.back();
			myRoomLoot.pop_back();

			if (found.IsSpell())
			{
				aPlayer.ActivateSpell(found);
			}
			else
			{
				aPlayer.TryAddItem(found);
			}
		}
		system("pause");
		return aCurrentRoomNumber;
	}

	if (myHasChest && choice == chestOption)
	{
		system("cls");
		std::cout << "=== OPENING CHEST ===\n";

		std::vector<Loot> droppedItems = myChest.Open();
		for (const auto& item : droppedItems)
		{
			std::cout << "You got " << item.GetName() << "!";
			myRoomLoot.push_back(item);
		}

		myHasChest = false;
		system("pause");
		return aCurrentRoomNumber;
	}

	int doorChoice = choice - firstDoorMenuNum;
	if (doorChoice >= 0 && doorChoice < myDoors.size())
	{
		Door* selectedDoor = myDoors[doorChoice];

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
				bool success = selectedDoor->AttemptUnlock(aPlayer, lockChoice);
				system("pause");

				if (!success) return aCurrentRoomNumber;
			}
			else
			{
				return aCurrentRoomNumber;
			}
		}

		aPlayer.UpdateSpellTimer();
		return selectedDoor->GetDestination(aCurrentRoomNumber);
	}
	return aCurrentRoomNumber;
}