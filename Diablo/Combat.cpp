#include "Combat.h"
#include <iostream>

bool Combat::HasLivingEnemies(std::vector<Enemy>& enemies)
{
    int numEnemies = static_cast<int>(enemies.size());
    for (int i = 0; i < numEnemies; ++i)
    {
        if (enemies[i].IsAlive()) return true;
    }
    return false;
}

void Combat::Fight(Player& player, std::vector<Enemy>& enemies)
{
    std::cout << "Monsters appear! You must defeat them to proceed!\n";

    while (HasLivingEnemies(enemies) && player.IsAlive())
    {
        std::cout << "\n--- YOUR TURN ---\n";
        std::vector<int> livingEnemyIndices;
        int optionNum = 1;

        int numEnemies = static_cast<int>(enemies.size());
        for (int i = 0; i < numEnemies; ++i)
        {
            if (enemies[i].IsAlive())
            {
                std::cout << "[" << optionNum << "] Attack " << enemies[i].GetName()
                    << " (HP: " << enemies[i].GetHealth() << "/" << enemies[i].GetMaxHealth() << ")\n";

                livingEnemyIndices.push_back(i);
                optionNum++;
            }
        }
        std::cout << "Choose target: ";
        int targetChoice;
        std::cin >> targetChoice;

        int selectedIdx = targetChoice - 1;
        if (selectedIdx >= 0 && selectedIdx < static_cast<int>(livingEnemyIndices.size()))
        {
            int enemyVecIdx = livingEnemyIndices[selectedIdx];

            int damageToEnemy = player.HasOneShot() ? 999 : player.GetAttackValue();
            enemies[enemyVecIdx].LoseHealth(damageToEnemy);
            std::cout << "You hit " << enemies[enemyVecIdx].GetName() << " for " << damageToEnemy << " damage!\n";

            if (!enemies[enemyVecIdx].IsAlive())
            {
                std::cout << enemies[enemyVecIdx].GetName() << " is defeated!\n";
            }
        }

        if (HasLivingEnemies(enemies) && player.IsAlive())
        {
            std::cout << "\n--- MONSTERS TURN ---\n";
            for (int i = 0; i < numEnemies; ++i)
            {
                if (enemies[i].IsAlive())
                {
                    if (player.HasGodMode())
                    {
                        std::cout << enemies[i].GetName() << " attacks, but you are IMMORTAL!\n";
                    }
                    else
                    {
                        int damageToPlayer = enemies[i].GetAttackValue() - player.GetDefence();
                        if (damageToPlayer < 1) damageToPlayer = 1;

                        player.LoseHealth(damageToPlayer);
                        std::cout << enemies[i].GetName() << " hits you for " << damageToPlayer << " damage!\n";
                    }
                }
            }
        }
        system("pause");
    }
}