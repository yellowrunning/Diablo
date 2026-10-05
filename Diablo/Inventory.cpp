#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {}

bool Inventory::AddItem(Loot aLoot, int aStrength)
{
    int currentWeight = 0;
    for (const auto& item : myItems)
    {
        currentWeight += item.GetWeight();
    }

    int maxCapacity = aStrength * 2;

    if (currentWeight + aLoot.GetWeight() > maxCapacity)
    {
        std::cout << "Cannot pick up " << aLoot.GetName() << "! Too heavy! ("
            << currentWeight + aLoot.GetWeight() << "/" << maxCapacity << " kg)\n";
        return false;
    }

    myItems.push_back(aLoot);
    std::cout << "You picked up: " << aLoot.GetName() << "!\n";
    return true;
}

void Inventory::PrintInventory() const
{
    std::cout << "\n=== INVENTORY ===\n";
    if (myItems.empty())
    {
        std::cout << "Your bag is empty.\n";
    }
    else
    {
        for (const auto& item : myItems)
        {
            std::cout << "- " << item.GetName() << " (Weight: " << item.GetWeight()
                << " kg, ATK+" << item.GetAttack() << ", DEF+" << item.GetDefence() << ")\n";
        }
    }
}

int Inventory::GetTotalAttackBonus() const
{
    int bonus = 0;
    for (const auto& item : myItems) bonus += item.GetAttack();
    return bonus;
}

int Inventory::GetTotalDefenceBonus() const
{
    int bonus = 0;
    for (const auto& item : myItems) bonus += item.GetDefence();
    return bonus;
}
