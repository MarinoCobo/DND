#include "SpellBook.h"
#include <iostream>

void SpellBook::addSpell(Spell spell)
{
    this->spellBook.push_back(spell);
}
Spell* SpellBook::findSpellByName(std::string name)
{
    for(int j = 0; j < this->spellBook.size(); j++)
    {
        if (spellBook[j].getName() == name)
        {
            return &spellBook[j];
        }
    }
    return nullptr;
}
void SpellBook::showAllSpells()
{
    for(int j = 0; j < this->spellBook.size(); j++)
    {
        std::cout << spellBook[j].getName();
        if (j < this->spellBook.size() - 1)
        {
            std::cout << ", ";
        }
    } 
}
bool SpellBook::deleteSpell(std::string name)
{
    for(int j = 0; j < this->spellBook.size(); j++)
    {
        if (spellBook[j].getName() == name)
        {
            spellBook.erase(spellBook.begin() + j);
            return true;
        }
    } 
    return false;
}