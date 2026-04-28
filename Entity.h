#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <array>
#include "DNDTypes.h"

class Entity
{
    //----------------------------------------------PROTECTED----------------------------------------------
    protected:
        std::string name;
        int armorClass;
        int hitPoints;
        int walkSpeed;
        int flySpeed;
        int swimSpeed;
        std::array<int, static_cast<int>(Ability::Count)> abilityScores;
        std::array<int, static_cast<int>(Ability::Count)> savingThrows;
        std::array<int, static_cast<int>(Skill::Count)> skillBonuses;

    //----------------------------------------------PUBLIC----------------------------------------------    
    public:
        //Constructor & destructor
        Entity(const std::string& name, int armorClass, int hitPoints, int walkSpeed, int flySpeed, int swimSpeed);
        virtual ~Entity();

        //Virtual Functions
        virtual void displayInfo() const = 0;
        virtual bool performAction(const std::string& actionName) = 0;

        // Setters
        void setName(const std::string& name);
        void setArmorClass(int armorClass);
        void setHitPoints(int hitPoints);
        void setWalkSpeed(int walkSpeed);
        void setFlySpeed(int flySpeed);
        void setSwimSpeed(int swimSpeed);
        void setAbilityScore(Ability ability, int value);
        void setSavingThrow(Ability ability, int bonus);
        void setSkillBonus(Skill skill, int bonus);

        //Getters
        std::string getName() const;
        int getArmorClass() const;
        int getHitPoints() const;
        int getWalkSpeed() const;
        int getFlySpeed() const;
        int getSwimSpeed() const;
        int getAbilityScore(Ability ability) const;
        int getSavingThrow(Ability ability) const;
        void displaySavingThrows() const;
        int getSkillBonus(Skill skill) const;
};

#endif