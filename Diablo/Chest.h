#pragma once
#include <vector>
#include "Loot.h"

class Chest
{
private:
    std::vector<Loot> myStoredLoot;
    bool myIsOpened;

public:
    Chest();
    Chest(std::vector<Loot> aLootList);
    bool IsOpened() const;
    std::vector<Loot> Open();
};