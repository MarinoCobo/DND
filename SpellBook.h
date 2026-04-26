#ifndef SPELLBOOK_H
#define SPELLBOOK_H
#include <vector>
#include <string>
#include "Spell.h"

class SpellBook
{
    private:
        std::vector<Spell> spellBook;
    
    public:
        void addSpell(Spell spell);
        Spell* findSpellByName (std::string name);
        void showAllSpells();
        bool deleteSpell(std::string name);
};

#endif