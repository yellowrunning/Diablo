#include "Enemy.h"

Enemy::Enemy(std::string aName, int aHealth, int anAttack, int aDefence)
{
	myName = aName;
	myHealth = aHealth;
	myMaxHealth = aHealth;
	myAttackValue = anAttack;
	myDefence = aDefence;
}

std::string Enemy::GetName() const { return myName; }
int Enemy::GetAttackValue() const { return myAttackValue; }
int Enemy::GetDefence() const { return myDefence; }
int Enemy::GetHealth() const { return myHealth; }
int Enemy::GetMaxHealth() const { return myMaxHealth; }
bool Enemy::IsAlive() const { return myHealth > 0; }

void Enemy::LoseHealth(int damage)
{
	myHealth -= damage;
}
