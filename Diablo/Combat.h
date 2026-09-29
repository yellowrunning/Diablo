#pragma once
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Combat
{
public:
    static void Fight(Player& player, std::vector<Enemy>& enemies);

private:
    static bool HasLivingEnemies(std::vector<Enemy>& enemies);
};
