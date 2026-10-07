#include "Loot.h"
#include "ItemFactory.h"

const std::string& Loot::GetName() const { static std::string empty = ""; if (!myType) return empty; return myType->name; }
int Loot::GetHealth() const { return myType ? myType->addHealth : 0; }
int Loot::GetAttack() const { return myType ? myType->addAttack : 0; }
int Loot::GetDefence() const { return myType ? myType->addDefence : 0; }
int Loot::GetWeight() const { return myType ? myType->weight : 0; }
bool Loot::IsSpell() const { return myType ? myType->isSpell : false; }

