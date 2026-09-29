#pragma once
#include <iostream>

class Enemy
{
private:
	std::string name;
	int health;
	int maxHealth;
	int attackValue;
	int defence;

public:
	Enemy(std::string aName, int ahealth, int anattack, int adefence);

	std::string GetName() const;
	int GetAttackValue() const;
	int GetDefence() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	bool IsAlive() const;
	void LoseHealth(int damage);
};