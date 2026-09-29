#include "Combat.h"
#include <iostream>

bool Combat::HasLivingEnemies(std::vector<Enemy>& enemies)
{
    for (int i = 0; i < enemies.size(); ++i)
    {
        if (enemies[i].IsAlive()) return true;
    }
    return false;
}

void Combat::Fight(Player& player, std::vector<Enemy>& enemies)
{

    while (HasLivingEnemies(enemies) && player.IsAlive())
    {
        system("cls");
        std::cout << "Monsters appear! You must defeat them to proceed!\n";

        std::cout << "\n--- YOUR TURN ---\n";
        std::vector<int> targets;
        int menuNum = 1;

        for (int i = 0; i < enemies.size(); ++i)
        {
            if (enemies[i].IsAlive())
            {
                std::cout << "[" << menuNum << "] Attack " << enemies[i].GetName()
                    << " (HP: " << enemies[i].GetHealth() << "/" << enemies[i].GetMaxHealth() << ")\n";

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

            int damageToEnemy = player.GetAttackValue() - enemies[monsterId].GetDefence();
            if (damageToEnemy < 1) damageToEnemy = 1;

            if (player.HasOneShot()) damageToEnemy = 999;

            enemies[monsterId].LoseHealth(damageToEnemy);

            system("cls");
            std::cout << "You hit " << enemies[monsterId].GetName() << " for " << damageToEnemy << " damage!\n";

            if (!enemies[monsterId].IsAlive())
            {
                std::cout << enemies[monsterId].GetName() << " is defeated!\n";
            }
        }

        if (HasLivingEnemies(enemies) && player.IsAlive())
        {
            std::cout << "\n--- MONSTERS TURN ---\n";
            for (int i = 0; i < enemies.size(); ++i)
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
    system("cls");
}