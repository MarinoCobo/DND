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

    }
}
int CastingTime::getAmount() const
{
    
}
TimeUnit CastingTime::getTimeUnit() const
{
}
