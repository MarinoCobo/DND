#include "Entity.h"
#include <iostream>
#include <iomanip>

//Constructor and Destructor
Entity::Entity(const std::string& name, int armorClass, int hitPoints, int walkSpeed, int flySpeed, int swimSpeed)
    : name(name), armorClass(armorClass), hitPoints(hitPoints), walkSpeed(walkSpeed), flySpeed(flySpeed), swimSpeed(swimSpeed)
{
    abilityScores.fill(0);
    savingThrows.fill(0);
    skillBonuses.fill(0);
}

Entity::~Entity()
{
}

//Setters definitions
void Entity::setName(const std::string& name)
{
    this->name = name;
}
void Entity::setArmorClass(int armorClass)
{
    this->armorClass = armorClass;
}
void Entity::setHitPoints(int hitPoints)
{
    this->hitPoints = hitPoints;
}
void Entity::setWalkSpeed(int walkSpeed)
{
    this->walkSpeed = walkSpeed;
}
void Entity::setFlySpeed(int flySpeed)
{
    this->flySpeed = flySpeed;
}
void Entity::setSwimSpeed(int swimSpeed)
{
    this->swimSpeed = swimSpeed;
}
void Entity::setAbilityScore(Ability ability, int value)
{
    abilityScores[static_cast<int>(ability)] = value;
}
void Entity::setSavingThrow(Ability ability, int bonus)
{
    savingThrows[static_cast<int>(ability)] = bonus;
}
void Entity::setSkillBonus(Skill skill, int bonus)
{
    skillBonuses[static_cast<int>(skill)] = bonus;
}

//Getters definitions
std::string Entity::getName() const
{
    return name;
}
int Entity::getArmorClass() const
{
    return armorClass;
}
int Entity::getHitPoints() const
{
    return hitPoints;
}
int Entity::getWalkSpeed() const
{
    return walkSpeed;
}   
int Entity::getFlySpeed() const
{
    return flySpeed;
}
int Entity::getSwimSpeed() const
{
    return swimSpeed;
}
int Entity::getAbilityScore(Ability ability) const
{
    return abilityScores[static_cast<int>(ability)];
}   
int Entity::getSavingThrow(Ability ability) const
{
    return savingThrows[static_cast<int>(ability)];
}
void Entity::displaySavingThrows() const
{
    const std::array<std::string, static_cast<int>(Ability::Count)> abilityNames = {
        "Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"
    };
    for(size_t j=0; j<savingThrows.size(); j++)
    {
        std::cout << std::left << std::setw(20) << abilityNames[j];
    }
    std::cout << std::endl;
    for(size_t j=0; j<savingThrows.size(); j++)
    {
        std::cout << std::left << std::setw(20) << ("+" + std::to_string(savingThrows[j]));
    }
}
int Entity::getSkillBonus(Skill skill) const
{
    return skillBonuses[static_cast<int>(skill)];
}