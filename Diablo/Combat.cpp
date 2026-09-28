#include <iostream>
#include "Player.h"
#include "Enemy.h"

struct Combat
{
    Player player;
    Enemy enemy;

	bool IsPlayerAlive() { return player.IsAlive(); }
	bool IsEnemyAlive() { return enemy.IsAlive(); }

};