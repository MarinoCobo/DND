#include "CastingTime.h"
#include <iostream>

static std::string timeUnitToString(TimeUnit unit, int amount)
{
    switch (unit)
    {
        case TimeUnit::Action:
            if (amount == 1)
            {
                return "Action";
            }
            else
            {
                return "Actions";   
            }

        case TimeUnit::BonusAction:
            if (amount == 1)
            {
                return "Bonus Action";
            }
            else
            {
                return "Bonus Actions";   
            }

        case TimeUnit::Reaction:
            if (amount == 1)
            {
                return "Reaction";
            }
            else
            {
                return "Reactions";   
            }

        case TimeUnit::Round:
            if (amount == 1)
            {
                return "Round";
            }
            else
            {
                return "Rounds";   
            }

        case TimeUnit::Minute:
            if (amount == 1)
            {
                return "Minute";
            }
            else
            {
                return "Minutes";   
            }

        case TimeUnit::Hour:
            if (amount == 1)
            {
                return "Hour";
            }
            else
            {
                return "Hours";   
            }

        case TimeUnit::Day:
            if (amount == 1)
            {
                return "Day";
            }
            else
            {
                return "Days";   
            }

        case TimeUnit::Special:
            return "Special";

        default:
            return "Unknown";
    }
}

//Constructor
CastingTime::CastingTime(int amount, TimeUnit unit)
    : amount(amount), unit(unit)
{
}

//Getters
void CastingTime::displayInfo() const 
{
    std::cout << amount << " " << timeUnitToString(unit, amount);
    std::cout << std::endl;
}
int CastingTime::getAmount() const
{
    return amount;
}
TimeUnit CastingTime::getTimeUnit() const
{
    return unit ;
}

//Setters
void CastingTime::setAmount(int amount)
{
    this->amount = amount;
}
void CastingTime::setTimeUnit(TimeUnit unit)
{
    this->unit = unit;
}