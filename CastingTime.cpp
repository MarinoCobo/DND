#include "CastingTime.h"
#include <iostream>

    
CastingTime::CastingTime(int amount, TimeUnit unit)
    : amount(amount), unit(unit)
{
}

void CastingTime::displayInfo() const 
{
    std::cout << "The casting time is: " << amount << " ";
    switch (unit)
    {

        case TimeUnit::Action:

            std::cout << "Action";

            break;

        case TimeUnit::BonusAction:

            std::cout << "Bonus Action";

            break;

        case TimeUnit::Reaction:

            std::cout << "Reaction";

            break;

        case TimeUnit::Round:

            std::cout << "Round";

            break;

        case TimeUnit::Minute:

            std::cout << "Minute";

            break;

        case TimeUnit::Hour:

            std::cout << "Hour";

            break;
        case TimeUnit::Day:

            std::cout << "Day";

            break;

        case TimeUnit::Special:

            std::cout << "Special";

            break;

    }
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
void CastingTime::setAmount(int amount)
{
    this->amount = amount;
}
void CastingTime::setTimeUnit(TimeUnit unit)
{
    this->unit = unit;
}