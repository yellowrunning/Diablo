#pragma once
#include <iostream>

// Forward declaration of EnemyType owned by EnemyFactory
struct EnemyType;

class Enemy
{
private:
	const EnemyType* myType = nullptr;
	int myHealth = 0;
	int myMaxHealth = 0;

public:
	// Construct from a shared EnemyType
	explicit Enemy(const EnemyType* aType = nullptr);

	std::string GetName() const;
	int GetAttackValue() const;
	int GetDefence() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	bool IsAlive() const;
	void LoseHealth(int damage);
};
