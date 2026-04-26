#include "Spell.h"
#include <iostream>

static std::string spellSchoolToString(SpellSchool school)
{
    switch (school)
    {
        case SpellSchool::Abjuration:
            return "Abjuration";
        case SpellSchool::Conjuration:
            return "Conjuration";
        case SpellSchool::Divination:
            return "Divination";
        case SpellSchool::Enchantment:
            return "Enchantment";
        case SpellSchool::Evocation:
            return "Evocation";
        case SpellSchool::Illusion:
            return "Illusion";
        case SpellSchool::Necromancy:
            return "Necromancy";
        case SpellSchool::Transmutation:
            return "Transmutation";
        default:
            return "Unknown";
    }
}

//Constructor
Spell::Spell(const std::string& name, int level, SpellSchool school, const CastingTime& castingTime, const SpellDuration& spellDuration, const std::string& description)
    : name(name), level(level), school(school), castingTime(castingTime), spellDuration(spellDuration), description(description)
{
}

//Getters

void Spell::displayInfo() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "School: " << spellSchoolToString(school) << std::endl;
    std::cout << "Casting time: ";
    castingTime.displayInfo();
    std::cout << "Duration: ";
    spellDuration.displayInfo();
    std::cout << "Description: " << description << std::endl;
}

std::string Spell::getName() const
{
    return name;
}
int Spell::getLevel() const
{
    return level;
}

SpellSchool Spell::getSchool() const
{
    return school;
}

const CastingTime& Spell::getCastingTime() const
{
    return this->castingTime;
}

const SpellDuration& Spell::getSpellDuration() const
{
    return this->spellDuration;
}

std::string Spell::getDescription() const
{
    return description;
}

//Setters
void Spell::setName(const std::string& name)
{
    this->name = name;
}
void Spell::setLevel(int level)
{
    this->level = level;
}
void Spell::setSpellSchool(SpellSchool school)
{
    this->school = school;
}
void Spell::setCastingTime(const CastingTime& castingTime)
{
    this->castingTime = castingTime;   
}
void Spell::setDuration(const SpellDuration& spellDuration)
{
    this->spellDuration = spellDuration;
}
void Spell::setDescription(const std::string& description)
{
    this->description = description;
}



        
