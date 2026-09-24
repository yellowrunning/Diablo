#pragma once
#include <iostream>

class Enemy
{
private:
	int health;
	int attackValue;

public:
	Enemy(int ahealth, int anattack)
	{
		health = ahealth;
		anattack = attackValue;
	}

	int GetAttackValue() { return attackValue; }
	bool IsAlive() { return health > 0; }

	void LoseHealth(int damage)
	{
		health -= damage;
	}
};