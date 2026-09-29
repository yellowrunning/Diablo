#pragma once

class Player;

class Door
{
private:
    int roomA_Number;
    int roomB_Number;
    bool isLocked;

public:
    Door(int aRoomA, int aRoomB, bool locked = false);
    int GetDestination(int currentRoomNumber) const;
    bool IsLocked() const;
    void Unlock();

    bool AttemptUnlock(Player& aplayer, int lockChoice);
};