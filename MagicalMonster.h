#ifndef MAGICALMONSTER_H
#define MAGICALMONSTER_H

#include "Monster.h"
#include "SpellCaster.h"
#include "SpellUse.h"
#include "DNDTypes.h"
#include <vector>
#include <string>

class MagicalMonster : public Monster, public SpellCaster
{
private:
    std::vector<SpellUse> spellUses;
    Ability spellcastingAbility;
    int spellSaveDC;
    int spellAttackBonus;

public:
    MagicalMonster(
        const std::string& name,
        int armorClass,
        int hitPoints,
        int walkSpeed,
        int flySpeed,
        int swimSpeed,
        Size size,
        CreatureType creatureType,
        double challengeRating,
        Ability spellcastingAbility,
        int spellSaveDC,
        int spellAttackBonus
    );

    void setSpellcastingAbility(Ability ability);
    Ability getSpellcastingAbility() const;

    void addSpellUse(Spell* spell, int maxUses, RechargeType rechargeType);
    bool castSpell(const std::string& spellName) override;


    int calculateMagicPower() const override;

    //Monster functions override
    void displayInfo() const override;
    bool performAction(const std::string& actionName) override;

    int calculateThreat() const override;
    Monster* clone() const override;
};

#endif