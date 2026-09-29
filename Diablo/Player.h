#pragma once
#include <iostream>

class Player
{
private:
	std::string name = "The Player";
	int strength = 10;
	int agility = 10;
	int vitality = 10;
	int currentHealth;

	bool godMode = false;
	bool oneShotMode = false;

public:
	Player();

	int GetMaxHealth() { return vitality * 6 + strength * 4 + agility * 3; }
	int GetAttackValue() { return strength + agility; }
	int GetDefence() { return strength + agility / 3; }
	int GetStrength() const { return strength; }
	int GetAgility() const { return agility; }

	bool IsAlive() { return currentHealth > 0; }
	void LoseHealth(int damage);
	void ShowStats();

	void ToggleGodMode() { godMode = !godMode; }
	void ToggleOneShot() { oneShotMode = !oneShotMode; }
	bool HasGodMode() const { return godMode; }
	bool HasOneShot() const { return oneShotMode; }
};
