#include "Enemy.h"
#include "EnemyFactory.h"

Enemy::Enemy(const EnemyType* aType)
{
	myType = aType;
	if (myType)
	{
		myHealth = myType->health;
		myMaxHealth = myType->health;
	}
}

std::string Enemy::GetName() const { return myType ? myType->name : std::string(); }
int Enemy::GetAttackValue() const { return myType ? myType->attack : 0; }
int Enemy::GetDefence() const { return myType ? myType->defence : 0; }
int Enemy::GetHealth() const { return myHealth; }
int Enemy::GetMaxHealth() const { return myMaxHealth; }
bool Enemy::IsAlive() const { return myHealth > 0; }

void Enemy::LoseHealth(int damage)
{
	myHealth -= damage;
}
