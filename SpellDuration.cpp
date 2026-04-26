#include "SpellDuration.h"
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

SpellDuration::SpellDuration(int amount, TimeUnit unit, bool requiresConcentration, bool isInstantaneous, bool isUntilDispelled)
    : amount(amount), unit(unit), requiresConcentration(requiresConcentration), isInstantaneous(isInstantaneous), isUntilDispelled(isUntilDispelled)
{
}

void SpellDuration::displayInfo() const
{
    if(isInstantaneous)
    {
        std::cout << "Instantaneous" << std::endl;
    }
    else
    {
        if(isUntilDispelled)
        {
            std::cout << "Until dispelled" << std::endl;
        }
        else
        {
            std::cout << amount << " " << timeUnitToString(unit, amount) << std::endl;
        }
    }
    if(requiresConcentration)
    {
        std::cout << "This spell requires concentration.";
        std::cout << std::endl;
    }
}

int SpellDuration::getAmount() const
{
    return amount;
}

TimeUnit SpellDuration::getTimeUnit() const
{
    return unit;
}

bool SpellDuration::getRequiresConcentration() const
{
    return requiresConcentration;
}

bool SpellDuration::getIsInstantaneous() const
{
    return isInstantaneous;
}

bool SpellDuration::getIsUntilDispelled() const
{
    return isUntilDispelled;
}
