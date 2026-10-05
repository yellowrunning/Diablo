#pragma once
#include <iostream>
#include <string>
#include "Inventory.h"
#include "SpellSystem.h" 

class Player
{
private:
	std::string myName = "The Player";
	int myStrength = 10;
	int myAgility = 10;
	int myVitality = 10;
	int myCurrentHealth;

	bool myGodMode = false;
	bool myOneShotMode = false;

	Inventory myInventory;
	SpellSystem mySpells;

public:
	Player();

	int GetMaxHealth() { return myVitality * 6 + myStrength * 4 + myAgility * 3; }
	int GetAttackValue() { return myStrength + myAgility + myInventory.GetTotalAttackBonus() + mySpells.GetAttackBonus(); }
	int GetDefence() { return myStrength + myAgility / 3 + myInventory.GetTotalDefenceBonus(); }
	int GetStrength() const { return myStrength; }
	int GetAgility() const { return myAgility; }
	int GetHealth() const { return myCurrentHealth; }

	bool IsAlive() { return myCurrentHealth > 0; }
	void LoseHealth(int aDamage);
	void ShowStats();

	void ToggleGodMode() { myGodMode = !myGodMode; }
	void ToggleOneShot() { myOneShotMode = !myOneShotMode; }
	bool HasGodMode() const { return myGodMode; }
	bool HasOneShot() const { return myOneShotMode; }

	bool TryAddItem(Loot aLoot) { return myInventory.AddItem(aLoot, myStrength); }
	void ActivateSpell(Loot aSpell) { mySpells.Activate(aSpell); }
	void UpdateSpellTimer() { mySpells.UpdateTimer(); }
};
