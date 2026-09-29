#include "Game.h"
#include <iostream>

Game::Game()
{
    currentRoomNumber = 0;
    winRoomNumber = 4;
}

void Game::ShowMainMenu()
{
    int choice = 0;
    while (choice != 1)
    {
        system("cls");
        std::cout << "===== Diablo =====\n";
        std::cout << "[1] Play Game\n";
        std::cout << "[2] Toggle God Mode (Cheats)   [" << (player.HasGodMode() ? "ON" : "OFF") << "]\n";
        std::cout << "[3] Toggle One-Shot Kill (Cheats)   [" << (player.HasOneShot() ? "ON" : "OFF") << "]\n";
        std::cout << "[4] Exit Game\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        if (choice == 2) player.ToggleGodMode();
        if (choice == 3) player.ToggleOneShot();
        if (choice == 4) exit(0);
    }
}

void Game::SetupDungeon()
{
    Room room1("The Entrance");
    room1.AddEnemy(Enemy("Goblin", 15, 3, 2));

    Room room2("The Great Hall");
    room2.AddEnemy(Enemy("Skeleton", 20, 4, 3));

    Room room3("The Crypt");
    room3.AddEnemy(Enemy("Zombie", 25, 5, 4));

    Room room4("The Armory");
    room4.AddEnemy(Enemy("Orc", 35, 6, 5));

    Room room5("The Hell Gate");
    room5.AddEnemy(Enemy("Demon", 50, 10, 6));

    allDoors =
    {
        Door(0, 1, false),
        Door(1, 2, true),
        Door(2, 3, false),
        Door(3, 4, true)
    };

    room1.AddDoor(&allDoors[0]);
    room2.AddDoor(&allDoors[0]);

    room2.AddDoor(&allDoors[1]);
    room3.AddDoor(&allDoors[1]);

    room3.AddDoor(&allDoors[2]);
    room4.AddDoor(&allDoors[2]);

    room4.AddDoor(&allDoors[3]);
    room5.AddDoor(&allDoors[3]);

    dungeon = { room1, room2, room3, room4, room5 };
}

void Game::Run()
{
    ShowMainMenu();
    SetupDungeon();

    system("cls");
    std::cout << "The Game begins . . . \n";
    system("pause");

    while (player.IsAlive())
    {
        system("cls");
        currentRoomNumber = dungeon[currentRoomNumber].Interact(player, currentRoomNumber);

        if (currentRoomNumber == winRoomNumber && !dungeon[winRoomNumber].HasLivingEnemies())
        {
            break;
        }
    }

    system("cls");
    if (player.IsAlive())
    {
        std::cout << "\n*** VICTORY! You cleared the dungeon!\n";
    }
    else
    {
        std::cout << "\nGame Over. You died....\n";
    }
    system("pause");
}
