#include "SpellUse.h"
#include <iostream>

SpellUse::SpellUse(Spell* spell, int maxUses, RechargeType rechargeType)
    : spell(spell),
      maxUses(maxUses),
      remainingUses(maxUses),
      rechargeType(rechargeType)
{
}

bool SpellUse::cast()
{
    if (spell == nullptr)
    {
        std::cout << "Error: no spell assigned.\n";
        return false;
    }

    if (remainingUses <= 0)
    {
        std::cout << spell->getName() << " has no remaining uses.\n";
        return false;
    }

    remainingUses--;

    std::cout << "Casting spell: " << spell->getName() << std::endl;
    spell->displayInfo();

    return true;
}

RechargeType SpellUse::getRechargeType() const
{
    return rechargeType;
}

std::string SpellUse::getSpellName() const
{
    if (spell == nullptr)
    {
        return "Unknown Spell";
    }

    return spell->getName();
}

void SpellUse::resetUses()
{
    remainingUses = maxUses;
}

void SpellUse::displayInfo() const
{
    std::cout << "Spell: " << getSpellName() << std::endl;
    std::cout << "Uses: " << remainingUses << "/" << maxUses << std::endl;
    std::cout << "Recharge Type: " << static_cast<int>(rechargeType) << std::endl;
}