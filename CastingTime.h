#ifndef CASTINGTIME_H
#define CASTINGTIME_H

#include "DNDTypes.h"

class CastingTime
{
    private:
        int amount;
        TimeUnit unit;
    
    public:
        //Constructor
        CastingTime(int amount, TimeUnit unit);

        //Getters
        void displayInfo() const;
        int getAmount() const;
        TimeUnit getTimeUnit() const;
        
        //Setters
        void setAmount(int amount);
        void setTimeUnit(TimeUnit unit);
};
#endif