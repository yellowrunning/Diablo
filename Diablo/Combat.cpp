#include "Combat.h"
#include <iostream>

bool Combat::HasLivingEnemies(std::vector<Enemy>& aEnemies)
{
    for (int i = 0; i < aEnemies.size(); ++i)
    {
        if (aEnemies[i].IsAlive()) return true;
    }
    return false;
}

void Combat::Fight(Player& aPlayer, std::vector<Enemy>& aEnemies)
{

    while (HasLivingEnemies(aEnemies) && aPlayer.IsAlive())
    {
        system("cls");
        std::cout << "Monsters appear! You must defeat them to proceed!\n";

        std::cout << "\n--- YOUR TURN ---\n";
        std::vector<int> targets;
        int menuNum = 1;

        for (int i = 0; i < aEnemies.size(); ++i)
        {
            if (aEnemies[i].IsAlive())
            {
                std::cout << "[" << menuNum << "] Attack " << aEnemies[i].GetName()
                    << " (HP: " << aEnemies[i].GetHealth() << "/" << aEnemies[i].GetMaxHealth() << ")\n";

                targets.push_back(i);
                menuNum++;
            }
        }
        std::cout << "Choose target: ";
        int targetChoice;
        std::cin >> targetChoice;

        int choice = targetChoice - 1;
        if (choice >= 0 && choice < targets.size())
        {
        int monsterId = targets[choice];

            int damageToEnemy = aPlayer.GetAttackValue() - aEnemies[monsterId].GetDefence();
            if (damageToEnemy < 1) damageToEnemy = 1;

            if (aPlayer.HasOneShot()) damageToEnemy = 999;

            aEnemies[monsterId].LoseHealth(damageToEnemy);

            system("cls");
            std::cout << "You hit " << aEnemies[monsterId].GetName() << " for " << damageToEnemy << " damage!\n";

            if (!aEnemies[monsterId].IsAlive())
            {
                std::cout << aEnemies[monsterId].GetName() << " is defeated!\n";
            }
        }

        if (HasLivingEnemies(aEnemies) && aPlayer.IsAlive())
        {
            std::cout << "\n--- MONSTERS TURN ---\n";
            for (int i = 0; i < aEnemies.size(); ++i)
            {
                if (aEnemies[i].IsAlive())
                {
                    if (aPlayer.HasGodMode())
                    {
                        std::cout << aEnemies[i].GetName() << " attacks, but you are IMMORTAL!\n";
                    }
                    else
                    {
                        int damageToPlayer = aEnemies[i].GetAttackValue() - aPlayer.GetDefence();
                        if (damageToPlayer < 1) damageToPlayer = 1;

                        aPlayer.LoseHealth(damageToPlayer);
                        std::cout << aEnemies[i].GetName() << " hits you for " << damageToPlayer << " damage!\n";
                    }
                }
            }
        }
        system("pause");
    }
    system("cls");
}