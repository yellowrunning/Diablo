#pragma once
#include <string>

class Loot
{
private:
	std::string myItemName;
	int myAddHealth;
	int myAddAttack;
	int myAddDefence;
	int myWeight;
	bool myIsSpell;

public:
	Loot(const std::string& aName = "", int aHp = 0, int aAtk = 0, int aDef = 0, int aWeight = 0, bool aIsSpell = false)
		: myItemName(aName), myAddHealth(aHp), myAddAttack(aAtk), myAddDefence(aDef), myWeight(aWeight), myIsSpell(aIsSpell)
	{
	}

	const std::string& GetName() const { return myItemName; }
	int GetHealth() const { return myAddHealth; }
	int GetAttack() const { return myAddAttack; }
	int GetDefence() const { return myAddDefence; }
	int GetWeight() const { return myWeight; }
	bool IsSpell() const { return myIsSpell; }

	static Loot CreateItem(int aItemId);
};