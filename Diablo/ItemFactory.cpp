#include "ItemFactory.h"

ItemFactory::ItemFactory()
{
	myTypes.resize(6);
	myTypes[static_cast<int>(ItemId::EmptyBottle)] = ItemType("Empty Bottle", 0, 0, 0, 1, false);
	myTypes[static_cast<int>(ItemId::IronSword)] = ItemType("Iron Sword", 0, 5, 0, 4, false);
	myTypes[static_cast<int>(ItemId::SteelShield)] = ItemType("Steel Shield", 0, 0, 6, 8, false);
	myTypes[static_cast<int>(ItemId::BloodLust)] = ItemType("Blood Lust", 0, 10, 0, 0, true);
	myTypes[static_cast<int>(ItemId::HeavyPlate)] = ItemType("Heavy Plate Armor", 0, 0, 10, 12, false);
	myTypes[static_cast<int>(ItemId::RustyDagger)] = ItemType("Rusty Dagger", 0, 2, 0, 3, false);
}

const ItemType* ItemFactory::GetType(ItemId anId) const
{
	int idx = static_cast<int>(anId);
	if (idx >= 0 && idx < myTypes.size()) return &myTypes[idx];
	return &myTypes[0];
}

Loot ItemFactory::Create(ItemId anId) const
{
	return Loot(GetType(anId));
}
