#pragma once
#include <vector>
#include "Player.h"
#include "Rooms.h"
#include "Door.h"

class Game
{
private:
    Player myPlayer;
    std::vector<Room> myDungeon;
    std::vector<Door> myAllDoors;
    int myCurrentRoomNumber;
    int myWinRoomNumber;

public:
    Game();
    void Run();

private:
    void ShowMainMenu();
    void SetupDungeon();
};