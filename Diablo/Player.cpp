#include <iostream>
#include "Player.h"

Player::Player()
{
	currentHealth = GetMaxHealth();
}

void Player::LoseHealth(int damage)
{
    currentHealth -= damage;
}

void Player::ShowStats()
{
    std::cout << "\n=== STATS ===\n";
    std::cout << "Strength: " << strength << "\n";
    std::cout << "Agility: " << agility << "\n";
    std::cout << "Vitality: " << vitality << "\n";
    std::cout << "HP: " << currentHealth << " / " << GetMaxHealth() << "\n";
    std::cout << "Attack: " << GetAttackValue() << "\n";
    std::cout << "Defence: " << GetDefence() << "\=============\n\n";
}