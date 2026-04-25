#include "SpellDuration.h"
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

SpellDuration::SpellDuration(int amount, TimeUnit unit, bool requiresConcentration, bool isInstantaneous, bool isUntilDispelled)
    : amount(amount), unit(unit), requiresConcentration(requiresConcentration), isInstantaneous(isInstantaneous), isUntilDispelled(isUntilDispelled)
{
}

void SpellDuration::displayInfo() const
{
    if(isInstantaneous)
    {
        std::cout << "This spell is Instantaneous" << std::endl;
    }
    else
    {
        if(isUntilDispelled)
        {
            std::cout << "This spell lasts until dispelled" << std::endl;
        }
        else
        {
            std::cout << "The spell lasts " << amount << " " << timeUnitToString(unit) << std::endl;
        }
    }
    if(requiresConcentration)
    {
        std::cout << "This spell requires concentration.";
    }
}