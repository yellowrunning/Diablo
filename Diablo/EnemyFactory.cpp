#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{
	myTypes.resize(5);
	myTypes[static_cast<int>(EnemyId::Goblin)]   = EnemyType("Goblin", 20, 30, 2);
	myTypes[static_cast<int>(EnemyId::Skeleton)] = EnemyType("Skeleton", 25, 35, 3);
	myTypes[static_cast<int>(EnemyId::Zombie)]   = EnemyType("Zombie", 30, 40, 4);
	myTypes[static_cast<int>(EnemyId::Orc)]      = EnemyType("Orc", 35, 45, 5);
	myTypes[static_cast<int>(EnemyId::Demon)]    = EnemyType("Demon", 50, 50, 6);
}

const EnemyType* EnemyFactory::GetType(EnemyId anId) const
{
	int idx = static_cast<int>(anId);
	if (idx >= 0 && idx < myTypes.size()) return &myTypes[idx];
	return &myTypes[0];
}

Enemy EnemyFactory::Create(EnemyId anId) const
{
	const EnemyType* t = GetType(anId);
	return Enemy(t);
}
