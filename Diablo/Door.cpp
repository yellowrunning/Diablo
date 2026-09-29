#include "Door.h"

Door::Door(int aRoomA, int aRoomB)
{
    roomA_Number = aRoomA;
    roomB_Number = aRoomB;
}

int Door::GetDestination(int currentRoomNumber) const
{
    if (currentRoomNumber == roomA_Number) return roomB_Number;
    return roomA_Number;
}