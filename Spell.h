#ifndef SPELL_H
#define SPELL_H
#include <string>
#include "DNDTypes.h"

class Spell
{
    private:
        std::string name;
        int level;
        SpellSchool school;
        CastingTime castingTime;
        int duration;
        std::string description;

    public:
        //Constructir
        Spell(const std::string& name, int level, SpellSchool school, int castingTime, int duration, std::string description);
        
        //Getters
        std::string getName() const;
        int getLevel() const;
        void displayInfo() const;
        SpellSchool getSchool() const;
        int getCastingTime() const;
        int getDuration() const;

        //Setters
        void setName(const std::string& name);
        void setLevel(int level);
        void setSpellSchool(SpellSchool school);
        void setCastingTime(int castingTime);
        void setDuration(int duration);
        void setDescription(const std::string& description);
        
};
#endif
