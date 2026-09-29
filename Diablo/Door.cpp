#include "Door.h"
#include <iostream>
#include <random>
#include "Player.h"

Door::Door(int aRoomA, int aRoomB, bool locked)
{
    roomA_Number = aRoomA;
    roomB_Number = aRoomB;
    isLocked = locked;
}

int Door::GetDestination(int currentRoomNumber) const
{
    if (currentRoomNumber == roomA_Number) return roomB_Number;
    return roomA_Number;
}

bool Door::IsLocked() const { return isLocked; }
void Door::Unlock() { isLocked = false; }

bool Door::AttemptUnlock(Player& player, int lockChoice)
{
    std::random_device rd;
    std::mt19937 dice(rd());
    std::uniform_int_distribution<int> d20(1, 20);

    int roll = d20(dice);
    int targetScore = 20;

    if (lockChoice == 1)
    {
        int totalScore = roll + player.GetAgility();
        std::cout << "\nYou attempt to pick the lock...\n";
        std::cout << "You rolled: " << roll << " + Agility (" << player.GetAgility() << ") = Total: " << totalScore << "\n";

        if (totalScore >= targetScore)
        {
            std::cout << "Success! You picked the lock open.\n";
            isLocked = false;
            return true;
        }
        else
        {
            std::cout << "Failure! Your lockpicking failed.\n";
            return false;
        }
    }
    else if (lockChoice == 2)
    {
        int totalScore = roll + player.GetStrength();
        std::cout << "\nYou slam your body against the door...\n";
        std::cout << "You rolled: " << roll << " + Strength (" << player.GetStrength() << ") = Total: " << totalScore << "\n";

        if (totalScore >= targetScore)
        {
            std::cout << "Success! The door flies open.\n";
            isLocked = false;
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
