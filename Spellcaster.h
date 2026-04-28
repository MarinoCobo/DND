#ifndef SPELLCASTER_H
#define SPELLCASTER_H
#include <string>

class SpellCaster
{
    public:
        virtual ~SpellCaster() = default;

        virtual bool castSpell(const std::string& spellName) = 0;
        virtual int calculateMagicPower() const = 0;
};

#endif