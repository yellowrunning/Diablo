#include <iostream>
#include "Player.h"

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
    std::cout << "Attack: " << GetAttackValue() << "\n";
    std::cout << "Defence: " << GetDefence() << "\n====================\n\n";
}