#pragma once
#include <iostream>

class Enemy
{
private:
	std::string myName;
	int myHealth;
	int myMaxHealth;
	int myAttackValue;
	int myDefence;

public:
	Enemy(std::string aName, int aHealth, int anAttack, int aDefence);

	std::string GetName() const;
	int GetAttackValue() const;
	int GetDefence() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	bool IsAlive() const;
	void LoseHealth(int damage);
};