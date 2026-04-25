#ifndef SPELL_H
#define SPELL_H
#include <string>
#include "DNDTypes.h"
#include "CastingTime.h"

class Spell
{
    private:
        std::string name;
        int level;
        SpellSchool school; 
        CastingTime castingTime;
        std::string description;

    public:
        //Constructor
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
        void setCastingTimeAmount(int castingTime);
        void setCastingTimeUnit(TimeUnit unit);
        void setDescription(const std::string& description);
        
};
#endif
