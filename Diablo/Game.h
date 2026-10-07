#pragma once
#include <vector>
#include "Player.h"
#include "Rooms.h"
#include "Door.h"
#include "ItemFactory.h"
#include "EnemyFactory.h"

class Game
{
private:
    Player myPlayer;
    std::vector<Room*> myDungeon;
    std::vector<Door> myAllDoors;
    int myCurrentRoomNumber;
    int myWinRoomNumber;
    ItemFactory myItemFactory{ };
    EnemyFactory myEnemyFactory{ };

public:
    Game();
    void Run();

private:
    void ShowMainMenu();
    void SetupDungeon();
};