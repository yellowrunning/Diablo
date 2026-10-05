#include "Player.h"
#include <iostream>

Player::Player()
{
    myCurrentHealth = GetMaxHealth();
}

void Player::LoseHealth(int aDamage)
{
    myCurrentHealth -= aDamage;
}

void Player::ShowStats()
{
    std::cout << "\n=== STATS ===\n";
    std::cout << "Strength: " << myStrength << "\n";
    std::cout << "Agility: " << myAgility << "\n";
    std::cout << "Vitality: " << myVitality << "\n";
    std::cout << "HP: " << myCurrentHealth << " / " << GetMaxHealth() << "\n";
    std::cout << "Attack (with items): " << GetAttackValue() << "\n";
    std::cout << "Defence (with items): " << GetDefence() << "\n";

    if (mySpells.GetTurnsLeft() > 0)
    {
        std::cout << "Active Spell: +" << mySpells.GetAttackBonus() << " ATK (" << mySpells.GetTurnsLeft() << " rooms left)\n";
    }

    myInventory.PrintInventory();
    std::cout << "===========================\n\n";
}
