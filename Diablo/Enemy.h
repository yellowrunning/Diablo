#pragma once
#include <iostream>

class Enemy
{
private:
	std::string name;
	int health;
	int maxHealth;
	int attackValue;

public:
	Enemy(std::string aName, int ahealth, int anattack);

	std::string GetName() const;
	int GetAttackValue() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	bool IsAlive() const;
	void LoseHealth(int damage);
};