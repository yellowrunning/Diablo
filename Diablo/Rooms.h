#pragma once
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Player.h"

class Room
{
	int currentRoom = 0;
	std::vector<Room> rooms;
	rooms:Add(Room())
	rooms:Add(Room())
	Player player;
	while (currentRoom <= rooms.size() && player.IsAlive() == true)
	{
		rooms[currentRoom].EnterRoom(player);
		currentRoom++;
	}

	if (player.IsAlive() == true)
	{
	}