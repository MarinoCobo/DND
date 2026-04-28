#include "Encounter.h"
#include <iostream>

Encounter::Encounter(const std::string& difficulty)
    : difficulty(difficulty),
      totalExperience(0)
{
}

void Encounter::addMonster(Monster* monster)
{
    if (monster != nullptr)
    {
        monsters.push_back(monster);
        calculateTotalExperience();
    }
}

void Encounter::showEncounter() const
{
    std::cout << "\n===== ENCOUNTER =====\n";

    std::cout
        << "Difficulty: "
        << difficulty
        << std::endl;

    std::cout
        << "Total Experience: "
        << totalExperience
        << std::endl;

    std::cout
        << "\nMonsters:\n";

    if(monsters.empty())
    {
        std::cout << "No monsters in encounter.\n";
        return;
    }

    for(const Monster* monster : monsters)
    {
        monster->displayInfo();

        std::cout
            << "\n---------------------\n";
    }
}

int Encounter::calculateTotalExperience()
{
    totalExperience = 0;

    for(Monster* monster : monsters)
    {
        if(monster != nullptr)
        {
            totalExperience +=
                monster->calculateThreat();
        }
    }

    return totalExperience;
}

void Encounter::clearEncounter()
{
    monsters.clear();

    totalExperience = 0;
}