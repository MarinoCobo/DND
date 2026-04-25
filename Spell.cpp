#include "Spell.h"
#include <iostream>

std::string spellSchoolToString(SpellSchool school)
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
Spell::Spell(const std::string& name, int level, SpellSchool school, int castingTime, int duration, std::string description)
    : name(name), level(level), school(school), castingTime(castingTime), duration(duration), description(description)
{
}

//Getters
std::string Spell::getName() const
{
    return name;
}
int Spell::getLevel() const
{
    return level;
}
void Spell::displayInfo() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "School: " << spellSchoolToString(school) << std::endl;
    std::cout << "Casting Time: " << castingTime << std::endl;
    std::cout << "Duration: " << duration << std::endl;
    std::cout << "Description: " << description << std::endl;
}
SpellSchool Spell::getSchool() const
{
    return school;
}
int Spell::getCastingTime() const
{
    return castingTime;
}
int Spell::getDuration() const
{
    return duration;
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
void Spell::setCastingTime(int castingTime)
{
    this->castingTime = castingTime;
}
void Spell::setDuration(int duration)
{
    this->duration = duration;
}
void Spell::setDescription(const std::string& description)
{
    this->description = description;
}



        
