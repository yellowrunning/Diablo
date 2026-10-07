#pragma once
#include <string>
#include <vector>
#include "Loot.h"

struct ItemType
{
	std::string name;
	int addHealth;
	int addAttack;
	int addDefence;
	int weight;
	bool isSpell;

	ItemType(const std::string& aName = "", int aHp = 0, int aAtk = 0, int aDef = 0, int aWeight = 0, bool aIsSpell = false)
		: name(aName), addHealth(aHp), addAttack(aAtk), addDefence(aDef), weight(aWeight), isSpell(aIsSpell)
	{
	}
};

class ItemFactory
{
public:
	enum class ItemId
	{
		IronSword = 1,
		SteelShield = 2,
		BloodLust = 3,
		HeavyPlate = 4,
		RustyDagger = 5,
		EmptyBottle = 0
	};

	ItemFactory();

	// Create a Loot that references a shared ItemType owned by the factory
	// Only takes an enum indicating which item to create
	Loot Create(ItemId anId) const;

	// Provide access to internal ItemType for constructing Loot
	const ItemType* GetType(ItemId anId) const;

private:
	std::vector<ItemType> myTypes;
};
