#include "SpellBook.h"
#include <iostream>

void SpellBook::addSpell(const Spell& spell)
{
    this->spellBook.push_back(spell);
}

Spell* SpellBook::findSpellByName(const std::string& name)
{
    for(size_t j = 0; j < this->spellBook.size(); j++)
    {
        if (spellBook[j].getName() == name)
        {
            return &spellBook[j];
        }
    }
    return nullptr;
}
void SpellBook::showAllSpells() const
{
    for(size_t j = 0; j < this->spellBook.size(); j++)
    {
        std::cout << spellBook[j].getName();
        if (j < this->spellBook.size() - 1)
        {
            std::cout << ", ";
        }
    } 
    std::cout << std::endl;
}
bool SpellBook::deleteSpell(const std::string& name)
{
    for(size_t j = 0; j < this->spellBook.size(); j++)
    {
        if (spellBook[j].getName() == name)
        {
            spellBook.erase(spellBook.begin() + j);
            return true;
        }
    } 
    return false;
}