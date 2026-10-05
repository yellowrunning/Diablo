#include "Loot.h"
#include <iostream>

Loot Loot::CreateItem(int aItemId)
{
    switch (aItemId)
    {
    case 1:
        return Loot("Iron Sword", 0, 5, 0, 4, false);
    case 2:
        return Loot("Steel Shield", 0, 0, 6, 8, false);
    case 3:
        return Loot("Blood Lust", 0, 10, 0, 0, true);
    case 4:
        return Loot("Heavy Plate Armor", 0, 0, 10, 12, false);
    case 5:
        return Loot("Rusty Dagger", 0, 2, 0, 3, false);
    default:
        return Loot("Empty Bottle", 0, 0, 0, 1, false);
    }
}