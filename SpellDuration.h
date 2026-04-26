#ifndef SPELLDURATION_H
#define SPELLDURATION_H
#include "DNDTypes.h"

class SpellDuration
{
    private:
        int amount;
        TimeUnit unit;
        bool requiresConcentration;
        bool isInstantaneous;
        bool isUntilDispelled;
    
    public:
        //Constructor
        SpellDuration(int amount, TimeUnit unit, bool requiresConcentration, bool isInstantaneous, bool isUntilDispelled);
        
        //Getters
        void displayInfo() const;

        int getAmount() const;
        TimeUnit getTimeUnit() const;
        bool getRequiresConcentration() const;
        bool getIsInstantaneous() const;
        bool getIsUntilDispelled() const;
};
#endif
