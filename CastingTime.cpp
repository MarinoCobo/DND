#include "CastingTime.h"
#include <iostream>

static std::string timeUnitToString(TimeUnit unit)
{
    switch (unit)
    {
        case TimeUnit::Action:
            return "Action";

        case TimeUnit::BonusAction:
            return "Bonus Action";

        case TimeUnit::Reaction:
            return "Reaction";

        case TimeUnit::Round:
            return "Round";

        case TimeUnit::Minute:
            return "Minute";

        case TimeUnit::Hour:
            return "Hour";

        case TimeUnit::Day:
            return "Day";

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
    std::cout << amount << " " << timeUnitToString(unit) << std::endl;
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