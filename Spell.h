#ifndef SPELL_H
#define SPELL_H
#include <string>
#include "DNDTypes.h"
#include "CastingTime.h"
#include "SpellDuration.h"

class Spell
{
    private:
        std::string name;
        int level;
        SpellSchool school;
        CastingTime castingTime;
        SpellDuration spellDuration;
        std::string description;

    public:
        //Constructor
        Spell(const std::string& name, int level, SpellSchool school, const CastingTime& castingTime, const SpellDuration& spellDuration, const std::string& description);
        
        //Getters
        void displayInfo() const;

        std::string getName() const;
        int getLevel() const;
        SpellSchool getSchool() const;
        const CastingTime& getCastingTime() const;
        const SpellDuration& getSpellDuration() const;
        std::string getDescription() const;


        //Setters
        void setName(const std::string& name);
        void setLevel(int level);
        void setSpellSchool(SpellSchool school);
        void setCastingTime(const CastingTime& castingTime);
        void setDuration(const SpellDuration& spellDuration);
        void setDescription(const std::string& description);
        
};
#endif
