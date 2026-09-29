#pragma once

class Door
{
private:
    int roomA_Number;
    int roomB_Number;

public:
    Door(int aRoomA, int aRoomB);
    int GetDestination(int currentRoomNumber) const;
};