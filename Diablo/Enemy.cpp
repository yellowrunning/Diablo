#include "Enemy.h"

Enemy::Enemy(std::string aName, int ahealth, int anattack, int adefence)
{
	name = aName;
	health = ahealth;
	maxHealth = ahealth;
	attackValue = anattack;
	defence = adefence;
}

std::string Enemy::GetName() const { return name; }
int Enemy::GetAttackValue() const { return attackValue; }
int Enemy::GetDefence() const { return defence; }
int Enemy::GetHealth() const { return health; }
int Enemy::GetMaxHealth() const { return maxHealth; }
bool Enemy::IsAlive() const { return health > 0; }

void Enemy::LoseHealth(int damage)
{
	health -= damage;
}
