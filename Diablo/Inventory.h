#pragma once
#include <vector>
#include "Loot.h"

class Inventory
{
private:
    std::vector<Loot> myItems;

public:
    Inventory();
    bool AddItem(Loot aLoot, int aStrength);
    void PrintInventory() const;
    int GetTotalAttackBonus() const;
    int GetTotalDefenceBonus() const;
};
