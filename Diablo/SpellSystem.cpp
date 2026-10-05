#include "SpellSystem.h"
#include <iostream>

SpellSystem::SpellSystem()
{
    myActiveTurns = 0;
    myAttackBonus = 0;
}

void SpellSystem::Activate(Loot aSpell)
{
    myActiveTurns = 2;
    myAttackBonus = aSpell.GetAttack();
    std::cout << "Spell activated! " << aSpell.GetName() << " gives +" << myAttackBonus << " Attack for 2 rooms!\n";
}

void SpellSystem::UpdateTimer()
{
    if (myActiveTurns > 0)
    {
        myActiveTurns--;
        if (myActiveTurns == 0)
        {
            myAttackBonus = 0;
            std::cout << "\n[Your active spell has worn off!]\n";
            system("pause");
        }
    }
}

int SpellSystem::GetAttackBonus() const { return myAttackBonus; }
int SpellSystem::GetTurnsLeft() const { return myActiveTurns; }
