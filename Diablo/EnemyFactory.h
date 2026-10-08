#pragma once
#include <string>
#include <vector>
#include "Enemy.h"

struct EnemyType
{
	std::string name;
	int health;
	int attack;
	int defence;

	EnemyType(const std::string& aName = "", int aHp = 0, int aAtk = 0, int aDef = 0)
		: name(aName), health(aHp), attack(aAtk), defence(aDef)
	{
	}
};

class EnemyFactory
{
public:
	enum class EnemyId
	{
		Goblin = 0,
		Skeleton = 1,
		Zombie = 2,
		Orc = 3,
		Demon = 4
	};

	EnemyFactory();

	Enemy Create(EnemyId anId) const;

	const EnemyType* GetType(EnemyId anId) const;

private:
	std::vector<EnemyType> myTypes;
};
