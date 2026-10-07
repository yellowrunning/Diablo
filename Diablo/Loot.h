#pragma once
#include <string>

// Forward declaration of ItemType owned by ItemFactory
struct ItemType;

class Loot
{
private:
	const ItemType* myType = nullptr;

public:
	// Construct from an ItemType owned by the ItemFactory
	explicit Loot(const ItemType* aType = nullptr) : myType(aType) {}

	const std::string& GetName() const;
	int GetHealth() const;
	int GetAttack() const;
	int GetDefence() const;
	int GetWeight() const;
	bool IsSpell() const;
};
