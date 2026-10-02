#include "Door.h"
#include <iostream>
#include <random>
#include "Player.h"

Door::Door(int aRoomA, int aRoomB, bool locked)
{
    myRoomA_Number = aRoomA;
    myRoomB_Number = aRoomB;
    myIsLocked = locked;
}

int Door::GetDestination(int currentRoomNumber) const
{
    if (currentRoomNumber == myRoomA_Number) return myRoomB_Number;
    return myRoomA_Number;
}

bool Door::IsLocked() const { return myIsLocked; }
void Door::Unlock() { myIsLocked = false; }

bool Door::AttemptUnlock(Player& aPlayer, int aLockChoice)
{
    std::random_device rd;
    std::mt19937 dice(rd());
    std::uniform_int_distribution<int> d20(1, 20);

    int roll = d20(dice);
    int targetScore = 20;

    if (aLockChoice == 1)
    {
        int totalScore = roll + aPlayer.GetAgility();
        std::cout << "\nYou attempt to pick the lock...\n";
        std::cout << "You rolled: " << roll << " + Agility (" << aPlayer.GetAgility() << ") = Total: " << totalScore << "\n";

        if (totalScore >= targetScore)
        {
            std::cout << "Success! You picked the lock open.\n";
            myIsLocked = false;
            return true;
        }
        else
        {
            std::cout << "Failure! Your lockpicking failed.\n";
            return false;
        }
    }
    else if (aLockChoice == 2)
    {
            int totalScore = roll + aPlayer.GetStrength();
        std::cout << "\nYou slam your body against the door...\n";
        std::cout << "You rolled: " << roll << " + Strength (" << aPlayer.GetStrength() << ") = Total: " << totalScore << "\n";

        if (totalScore >= targetScore)
        {
            std::cout << "Success! The door flies open.\n";
            myIsLocked = false;
            return true;
        }
        else
        {
            std::cout << "Failure! The door didn't budge.\n";
            return false;
        }
    }

    return false;
}
