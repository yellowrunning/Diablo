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
    Room* room1 = new Room("The Entrance", myItemFactory);
    room1->AddEnemy(myEnemyFactory.Create(EnemyFactory::EnemyId::Goblin));
    room1->AddRoomLoot(myItemFactory.Create(ItemFactory::ItemId::IronSword));

    Room* room2 = new Room("The Great Hall", myItemFactory);
    room2->AddEnemy(myEnemyFactory.Create(EnemyFactory::EnemyId::Skeleton));
    room2->SetChest(Chest({ myItemFactory.Create(ItemFactory::ItemId::SteelShield) }));

    Room* room3 = new Room("The Crypt", myItemFactory);
    room3->AddEnemy(myEnemyFactory.Create(EnemyFactory::EnemyId::Zombie));
    room3->AddRoomLoot(myItemFactory.Create(ItemFactory::ItemId::BloodLust));

    Room* room4 = new Room("The Armory", myItemFactory);
    room4->AddEnemy(myEnemyFactory.Create(EnemyFactory::EnemyId::Orc));
    room4->AddRoomLoot(myItemFactory.Create(ItemFactory::ItemId::HeavyPlate));

    Room* room5 = new Room("The Hell Gate", myItemFactory);
    room5->AddEnemy(myEnemyFactory.Create(EnemyFactory::EnemyId::Demon));

    myAllDoors =
    {
        Door(0, 1, false),
        Door(1, 2, true),
        Door(2, 3, false),
        Door(3, 4, true)
    };

    room1->AddDoor(&myAllDoors[0]);
    room2->AddDoor(&myAllDoors[0]);

    room2->AddDoor(&myAllDoors[1]);
    room3->AddDoor(&myAllDoors[1]);

    room3->AddDoor(&myAllDoors[2]);
    room4->AddDoor(&myAllDoors[2]);

    room4->AddDoor(&myAllDoors[3]);
    room5->AddDoor(&myAllDoors[3]);

    myDungeon.clear();
    myDungeon.push_back(room1);
    myDungeon.push_back(room2);
    myDungeon.push_back(room3);
    myDungeon.push_back(room4);
    myDungeon.push_back(room5);
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
        myCurrentRoomNumber = myDungeon[myCurrentRoomNumber]->Interact(myPlayer, myCurrentRoomNumber);

        if (myCurrentRoomNumber == myWinRoomNumber && !myDungeon[myWinRoomNumber]->HasLivingEnemies())
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
