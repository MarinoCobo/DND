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
        void addSpell(const Spell& spell);
        Spell* findSpellByName (const std::string& name);
        void showAllSpells() const;
        bool deleteSpell(const std::string& name);
};

#endif