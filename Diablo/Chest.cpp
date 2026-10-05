#include "Chest.h"

Chest::Chest()
{
    myIsOpened = true;
}

Chest::Chest(std::vector<Loot> aLootList)
{
    myStoredLoot = aLootList;
    myIsOpened = false;
}

bool Chest::IsOpened() const { return myIsOpened; }

std::vector<Loot> Chest::Open()
{
    myIsOpened = true;
    std::vector<Loot> itemsToDrop = myStoredLoot;
    myStoredLoot.clear();
    return itemsToDrop;
}