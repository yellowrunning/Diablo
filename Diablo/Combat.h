#pragma once
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Combat
{
public:
    static void Fight(Player& aPlayer, std::vector<Enemy>& aEnemies);

private:
    static bool HasLivingEnemies(std::vector<Enemy>& aEnemies);
};
