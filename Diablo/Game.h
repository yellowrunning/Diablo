#pragma once
#include <vector>
#include "Player.h"
#include "Rooms.h"
#include "Door.h"

class Game
{
private:
    Player player;
    std::vector<Room> dungeon;
    std::vector<Door> allDoors;
    int currentRoomNumber;
    int winRoomNumber;

public:
    Game();
    void Run();

private:
    void ShowMainMenu();
    void SetupDungeon();
};