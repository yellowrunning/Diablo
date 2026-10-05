#pragma once
#include "Loot.h"

class SpellSystem
{
private:
    int myActiveTurns;
    int myAttackBonus;

public:
    SpellSystem();
    void Activate(Loot aSpell);
    void UpdateTimer();
    int GetAttackBonus() const;
    int GetTurnsLeft() const;
};
