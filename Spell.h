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
        int castingTime;
        int duration;
        std::string description;

    public:
        Spell(std::string name, int level, SpellSchool school, int castingTime, int duration, std::string description);
        std::string getName();
        int getLevel();
        void displayInfo();
        SpellSchool getSchool();
        int getCastingTime();
        int getDuration();

        
};
#endif
