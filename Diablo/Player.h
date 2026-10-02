#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string myName = "The Player";
	int myStrength = 10;
	int myAgility = 10;
	int myVitality = 10;
	int myCurrentHealth;

	bool myGodMode = false;
	bool myOneShotMode = false;

public:
	Player();

	int GetMaxHealth() { return myVitality * 6 + myStrength * 4 + myAgility * 3; }
	int GetAttackValue() { return myStrength + myAgility; }
	int GetDefence() { return myStrength + myAgility / 3; }
	int GetStrength() const { return myStrength; }
	int GetAgility() const { return myAgility; }

	bool IsAlive() { return myCurrentHealth > 0; }
	void LoseHealth(int aDamage);
	void ShowStats();

	void ToggleGodMode() { myGodMode = !myGodMode; }
	void ToggleOneShot() { myOneShotMode = !myOneShotMode; }
	bool HasGodMode() const { return myGodMode; }
	bool HasOneShot() const { return myOneShotMode; }
};
