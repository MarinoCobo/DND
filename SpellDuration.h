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
        SpellDuration(int amount, TimeUnit unit, bool requiresConcentration, bool isInstantaneous, bool isUntilDispelled);
        void displayInfo() const;
};
#endif
