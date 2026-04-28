#include "MagicalMonster.h"
#include <iostream>

MagicalMonster::MagicalMonster
(
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
)

: Monster
(
    name,
    armorClass,
    hitPoints,
    walkSpeed,
    flySpeed,
    swimSpeed,
    size,
    creatureType,
    challengeRating
),
spellcastingAbility(spellcastingAbility),
spellSaveDC(spellSaveDC),
spellAttackBonus(spellAttackBonus)
{
}

void MagicalMonster::setSpellcastingAbility(Ability ability)
{
    spellcastingAbility = ability;
}

Ability MagicalMonster::getSpellcastingAbility() const
{
    return spellcastingAbility;
}

void MagicalMonster::addSpellUse
(
    Spell* spell,
    int maxUses,
    RechargeType rechargeType
)
{
    spellUses.push_back
    (
        SpellUse
        (
            spell,
            maxUses,
            rechargeType
        )
    );
}

bool MagicalMonster::castSpell(const std::string& spellName)
{
    for (SpellUse& spellUse : spellUses)
    {
        if (spellUse.getSpellName() == spellName)
        {
            return spellUse.cast();
        }
    }

    std::cout << "Spell not found: " << spellName << std::endl;
    return false;
}

int MagicalMonster::calculateMagicPower() const
{
    return
        spellSaveDC + spellAttackBonus + static_cast<int>(spellUses.size()) * 5;
}

void MagicalMonster::displayInfo() const
{
    Monster::displayInfo();

    std::cout
        << "\nSpellcasting Ability: "
        << static_cast<int>(spellcastingAbility)
        << std::endl;

    std::cout
        << "Spell Save DC: "
        << spellSaveDC
        << std::endl;

    std::cout
        << "Spell Attack Bonus: "
        << spellAttackBonus
        << std::endl;

    std::cout
        << "\nSpells:\n";

    for(const SpellUse& spellUse : spellUses)
    {
        spellUse.displayInfo();
    }
}

bool MagicalMonster::performAction
(
    const std::string& actionName
)
{
    if(Monster::performAction(actionName))
    {
        return true;
    }

    if(castSpell(actionName))
    {
        return true;
    }

    return false;
}

int MagicalMonster::calculateThreat() const
{
    return static_cast<int>(
        getChallengeRating() * 10
        + getArmorClass()
        + getHitPoints()/10
        + calculateMagicPower()
    );
}

Monster* MagicalMonster::clone() const
{
    return new MagicalMonster(*this);
}