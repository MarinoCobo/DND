#ifndef CASTINGTIME_H
#define CASTINGTIME_H

#include "DNDTypes.h"

class CastingTime
{
    private:
        int amount;
        TimeUnit unit;
    
    public:
        CastingTime(int amount, TimeUnit unit);
        void displayInfo() const;
        int getAmount() const;
        TimeUnit getTimeUnit() const;
        void setAmount(int amount);
        void setTimeUnit(TimeUnit unit);
};
#endif