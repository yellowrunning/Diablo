#include "Enemy.h"

Enemy::Enemy(std::string aName, int ahealth, int anattack)
{
	name = aName;
	health = ahealth;
	maxHealth = ahealth;
	attackValue = anattack;
}

std::string Enemy::GetName() const { return name; }
int Enemy::GetAttackValue() const { return attackValue; }
int Enemy::GetHealth() const { return health; }
int Enemy::GetMaxHealth() const { return maxHealth; }
bool Enemy::IsAlive() const { return health > 0; }

void Enemy::LoseHealth(int damage)
{
	health -= damage;
}
