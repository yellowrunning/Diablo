#pragma once
#include <string>

class Loot
{
public:
	Loot(const std::string& name = "", int hp = 0, int atk = 0, int def = 0)
		: itemName(name), addHealth(hp), addAttack(atk), addDefence(def) {}

	const std::string& Name() const { return itemName; }
	int Health() const { return addHealth; }
	int Attack() const { return addAttack; }
	int Defence() const { return addDefence; }

private:
	std::string itemName;
	int addHealth;
	int addAttack;
	int addDefence;
};