#pragma once

class Player;

class Door
{
private:
    int myRoomA_Number;
    int myRoomB_Number;
    bool myIsLocked;

public:
    Door(int aRoomA, int aRoomB, bool aLocked = false);
    int GetDestination(int aCurrentRoomNumber) const;
    bool IsLocked() const;
    void Unlock();

    bool AttemptUnlock(Player& aPlayer, int aLockChoice);
};