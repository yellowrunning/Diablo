#pragma once
#include <iostream>

class Player
{
private:
	std::string name;
	int strength = 10;
	int agility = 10;
	int vitality = 10;

	int currentHealth;

public:
	Player();

	int GetMaxHealth() { return vitality * 6 + strength * 4 + agility * 3; }
	int GetAttackValue() { return strength + agility; }
	int GetDefence() { return strength + agility / 3; }

	bool IsAlive() { return currentHealth > 0; }
	void LoseHealth(int damage);
	void ShowStats();
};