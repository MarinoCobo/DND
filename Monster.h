#ifndef MONSTER_H
#define MONSTER_H
#include "DNDTypes.h"
#include "Trait.h"
#include "Action.h"
#include "Entity.h"
#include <vector>
#include <string>


class Monster : public Entity
{
    protected:
        Size size;
        CreatureType creatureType;
        double challengeRating;
        std::vector<Trait> traits;
        std::vector<Action> actions;
        std::vector<Action> reactions;
        std::vector<std::string> damageResistances;
        std::vector<std::string> damageImmunities;
        std::vector<std::string> conditionImmunities;
        std::vector<std::string> senses;
        std::vector<std::string> languages;

    public:
        //Constructor
        Monster(
            const std::string& name,
            int armorClass,
            int hitPoints,
            int walkSpeed,
            int flySpeed,
            int swimSpeed,
            Size size,
            CreatureType creatureType,
            double challengeRating
        );

        //Destructor
        virtual ~Monster();

        void displayInfo() const override;
        bool performAction(const std::string& actionName) override;

        //Setters
        void setSize(Size size);
        void setCreatureType(CreatureType creatureType);
        void setChallengeRating(double challengeRating);
        
        //Getters
        Size getSize() const;
        CreatureType getCreatureType() const;
        double getChallengeRating() const;

        //AddFunctions
        void addTrait(const std::string& name, const std::string& description);            
        void addAction(const std::string& name, const std::string& description);            
        void addReaction(const std::string& name, const std::string& description); 
        void addDamageResistance(const std::string& resistance);   
        void addDamageImmunity(const std::string& immunity);   
        void addConditionImmunity(const std::string& immunity);     
        void addSense(const std::string& sense);
        void addLanguage(const std::string& language);
        
        //RemoveFunctions
        bool removeTrait(const std::string& name);
        bool removeAction(const std::string& name);
        bool removeReaction(const std::string& name);
        bool removeDamageResistance(const std::string& resistance);
        bool removeDamageImmunity(const std::string& immunity);
        bool removeConditionImmunity(const std::string& immunity);
        bool removeSense(const std::string& sense);
        bool removeLanguage(const std::string& language);

        virtual int calculateThreat() const = 0;
        virtual Monster* clone() const = 0;

            
};

#endif