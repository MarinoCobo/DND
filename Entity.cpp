#include "Entity.h"
#include <iostream>

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