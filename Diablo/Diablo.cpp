#include <iostream>
#include "Player.h"
#include "Enemy.h"

/*
FUSK

bool godMode = false;
bool oneShot = false;
*/

void MainMenu()
{
	std::cout << "=====DIABLO=====\n";
    std::cout << "1. Play Game\n";
    std::cout << "2. Cheats\n";
    std::cout << "3. Exit Game\n";
    std::cout << "Choose: ";

}

int main()
{
	Player player;
	Enemy undead(20, 5);

    std::cout << "An enemy appears!\n";

        while (player.IsAlive() && undead.IsAlive())
        {
            undead.LoseHealth(player.GetAttackValue());
            std::cout << "You attack the monster!\n";

            if (undead.IsAlive())
            {
                player.LoseHealth(undead.GetAttackValue());
                std::cout << "Monster attacks you!\n";
            }
        }

    if (player.IsAlive())
    {
        std::cout << "You won the battle!\n";
    }
    else
    {
        std::cout << "Game Over. You died....\n"; [5]
    }
}