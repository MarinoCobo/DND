#ifndef SPELLUSE_H
#define SPELLUSE_H

#include "Spell.h"
#include "DNDTypes.h"
#include <string>

class SpellUse
{
private:
    Spell* spell;
    int maxUses;
    int remainingUses;
    RechargeType rechargeType;

public:
    SpellUse(Spell* spell, int maxUses, RechargeType rechargeType);

    bool cast();

    RechargeType getRechargeType() const;
    std::string getSpellName() const;

    void resetUses();
    void displayInfo() const;
};

#endif