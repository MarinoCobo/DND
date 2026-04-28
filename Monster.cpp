#include "Monster.h"
#include <iostream>

//Constructor
Monster::Monster(
    const std::string& name,
    int armorClass,
    int hitPoints,
    int walkSpeed,
    int flySpeed,
    int swimSpeed,
    Size size,
    CreatureType creatureType,
    double challengeRating
)
    : Entity(name, armorClass, hitPoints, walkSpeed, flySpeed, swimSpeed),
    size(size), 
    creatureType(creatureType),
    challengeRating(challengeRating)
{
}

//Destructor
Monster::~Monster()
{
}

void Monster::displayInfo() const
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Armor Class: " << getArmorClass() << std::endl;
    std::cout << "Hit Points: " << getHitPoints() << std::endl;
    std::cout << "Walk Speed: " << getWalkSpeed() << std::endl;
    std::cout << "Fly Speed: " << getFlySpeed() << std::endl;
    std::cout << "Swim Speed: " << getSwimSpeed() << std::endl;
    std::cout << "Challenge Rating: " << challengeRating << std::endl;
    
    std::cout << "\nTraits:\n";
    for (const Trait& trait : traits)
    {
        trait.displayInfo();
    }

    std::cout << "\nActions:\n";
    for (const Action& action : actions)
    {
        action.displayInfo();
    }

    std::cout << "\nReactions:\n";
    for (const Action& reaction : reactions)
    {
        reaction.displayInfo();
    }

    std::cout << "\nDamage Resistances:\n";
    for (const std::string& resistance : damageResistances)
    {
        std::cout << "- " << resistance << std::endl;
    }

    std::cout << "\nDamage Immunities:\n";
    for (const std::string& immunity : damageImmunities)
    {
        std::cout << "- " << immunity << std::endl;
    }

    std::cout << "\nCondition Immunities:\n";
    for (const std::string& immunity : conditionImmunities)
    {
        std::cout << "- " << immunity << std::endl;
    }

    std::cout << "\nSenses:\n";
    for (const std::string& sense : senses)
    {
        std::cout << "- " << sense << std::endl;
    }

    std::cout << "\nLanguages:\n";
    for (const std::string& language : languages)
    {
        std::cout << "- " << language << std::endl;
    }
}

bool Monster::performAction(const std::string& actionName) const
{
    for (const Action& action : actions)
    {
        if (action.getName() == actionName)
        {
            action.displayInfo();
            return true;
        }
    }
    return false;
}

//Setters
void Monster::setSize(Size size)
{
    this->size = size;
}

void Monster::setCreatureType(CreatureType creatureType)
{
    this->creatureType = creatureType;
}

void Monster::setChallengeRating(double challengeRating)
{
    this->challengeRating = challengeRating;
}

//Getters
Size Monster::getSize() const
{
    return size;
}

CreatureType Monster::getCreatureType() const
{
    return creatureType;
}

double Monster::getChallengeRating() const
{
    return challengeRating;
}

//AddFunctions
void Monster::addTrait(const std::string& name, const std::string& description)
{
    traits.push_back(Trait(name, description));
}

void Monster::addAction(const std::string& name, const std::string& description)
{
    actions.push_back(Action(name, description));
}

void Monster::addReaction(const std::string& name, const std::string& description)
{
    reactions.push_back(Action(name, description));
}

void Monster::addDamageResistance(const std::string& resistance)
{
    damageResistances.push_back(resistance);
}

void Monster::addDamageImmunity(const std::string& immunity)
{
    damageImmunities.push_back(immunity);
}

void Monster::addConditionImmunity(const std::string& immunity)
{
    conditionImmunities.push_back(immunity);
}

void Monster::addSense(const std::string& sense)
{
    senses.push_back(sense);
}

void Monster::addLanguage(const std::string& language)
{
    languages.push_back(language);
}

//RemoveFunctions
bool Monster::removeTrait(const std::string& name)
{
    for (auto it = traits.begin(); it != traits.end(); ++it)
    {
        if (it->getName() == name)
        {
            traits.erase(it);
            return true;
        }
    }
    return false;
}
bool Monster::removeAction(const std::string& name)
{
    for (auto it = actions.begin(); it != actions.end(); ++it)
    {
        if (it->getName() == name)
        {
            actions.erase(it);
            return true;
        }
    }
    return false;
}
bool Monster::removeReaction(const std::string& name)
{
    for (auto it = reactions.begin(); it != reactions.end(); ++it)
    {
        if (it->getName() == name)
        {
            reactions.erase(it);
            return true;
        }
    }
    return false;
}

bool Monster::removeDamageResistance(const std::string& resistance)
{
    auto it = std::find(damageResistances.begin(), damageResistances.end(), resistance);
    if (it != damageResistances.end())
    {
        damageResistances.erase(it);
        return true;
    }
    return false;
}

bool Monster::removeDamageImmunity(const std::string& immunity)\
{
    auto it = std::find(damageImmunities.begin(), damageImmunities.end(), immunity);
    if (it != damageImmunities.end())
    {
        damageImmunities.erase(it);
        return true;
    }
    return false;
}

bool Monster::removeConditionImmunity(const std::string& immunity)
{
    auto it = std::find(conditionImmunities.begin(), conditionImmunities.end(), immunity);
    if (it != conditionImmunities.end())
    {
        conditionImmunities.erase(it);
        return true;
    }
    return false;
}

bool Monster::removeSense(const std::string& sense)
{
    auto it = std::find(senses.begin(), senses.end(), sense);
    if (it != senses.end())
    {
        senses.erase(it);
        return true;
    }
    return false;
}
bool Monster::removeLanguage(const std::string& language)
{
    auto it = std::find(languages.begin(), languages.end(), language);
    if (it != languages.end())
    {
        languages.erase(it);
        return true;
    }
    return false;
}

