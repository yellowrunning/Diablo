#include "Game.h"
#include <iostream>

Game::Game()
{
    myCurrentRoomNumber = 0;
    myWinRoomNumber = 4;
}

void Game::ShowMainMenu()
{
    int choice = 0;
    std::string input;
    while (choice != 1)
    {
        system("cls");
        std::cout << "===== Diablo =====\n";
        std::cout << "[1] Play Game\n";
        std::cout << "[2] Toggle God Mode (Cheats)   [" << (myPlayer.HasGodMode() ? "ON" : "OFF") << "]\n";
        std::cout << "[3] Toggle One-Shot Kill (Cheats)   [" << (myPlayer.HasOneShot() ? "ON" : "OFF") << "]\n";
        std::cout << "[4] Exit Game\n";
        std::cout << "Choose: ";

        std::getline(std::cin, input);
        try
        {
            choice = std::stoi(input);
        }
        catch (...) {
            choice = 0;
        }

        if (choice == 2) myPlayer.ToggleGodMode();
        if (choice == 3) myPlayer.ToggleOneShot();
        if (choice == 4) exit(0);
    }
}

void Game::SetupDungeon()
{
    Room room1("The Entrance");
    room1.AddEnemy(Enemy("Goblin", 15, 16, 2));
    room1.AddRoomLoot(Loot::CreateItem(1));

    Room room2("The Great Hall");
    room2.AddEnemy(Enemy("Skeleton", 20, 18, 3));
    room2.SetChest(Chest({ Loot::CreateItem(2) }));

    Room room3("The Crypt");
    room3.AddEnemy(Enemy("Zombie", 25, 20, 4));
    room3.AddRoomLoot(Loot::CreateItem(3));

    Room room4("The Armory");
    room4.AddEnemy(Enemy("Orc", 35, 24, 5));
    room4.AddRoomLoot(Loot::CreateItem(4));

    Room room5("The Hell Gate");
    room5.AddEnemy(Enemy("Demon", 50, 30, 6));

    myAllDoors =
    {
        Door(0, 1, false),
        Door(1, 2, true),
        Door(2, 3, false),
        Door(3, 4, true)
    };

    room1.AddDoor(&myAllDoors[0]);
    room2.AddDoor(&myAllDoors[0]);

    room2.AddDoor(&myAllDoors[1]);
    room3.AddDoor(&myAllDoors[1]);

    room3.AddDoor(&myAllDoors[2]);
    room4.AddDoor(&myAllDoors[2]);

    room4.AddDoor(&myAllDoors[3]);
    room5.AddDoor(&myAllDoors[3]);

    myDungeon = { room1, room2, room3, room4, room5 };
}

void Game::Run()
{
    ShowMainMenu();
    SetupDungeon();

    system("cls");
    std::cout << "The Game begins\n";
    std::cout << "Objective: Escape the Hell Gate (reach room " << myWinRoomNumber << ") and defeat Demon.\n";
    system("pause");

    while (myPlayer.IsAlive())
    {
        system("cls");
        myCurrentRoomNumber = myDungeon[myCurrentRoomNumber].Interact(myPlayer, myCurrentRoomNumber);

        if (myCurrentRoomNumber == myWinRoomNumber && !myDungeon[myWinRoomNumber].HasLivingEnemies())
        {
            break;
        }
    }

    system("cls");
    if (myPlayer.IsAlive())
    {
        std::cout << "\nVICTORY! You cleared the dungeon!\n";
    }
    else
    {
        std::cout << "\nGame Over. You died....\n";
    }
    system("pause");
}
