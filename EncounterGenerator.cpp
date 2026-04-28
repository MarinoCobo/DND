#include "EncounterGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

EncounterGenerator::EncounterGenerator(Bestiary* bestiary)
    : bestiary(bestiary)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

Encounter EncounterGenerator::generateEncounter(
    int partyLevel,
    int partySize,
    const std::string& difficulty
)
{
    Encounter encounter(difficulty);

    if (bestiary == nullptr)
    {
        std::cout << "Error: bestiary is null.\n";
        return encounter;
    }

    int budget = calculateExperienceBudget(partyLevel, partySize, difficulty);

    double maxChallenge = static_cast<double>(partyLevel);

    if (difficulty == "easy")
    {
        maxChallenge = partyLevel * 0.5;
    }
    else if (difficulty == "medium")
    {
        maxChallenge = partyLevel * 0.75;
    }
    else if (difficulty == "hard")
    {
        maxChallenge = partyLevel;
    }
    else if (difficulty == "deadly")
    {
        maxChallenge = partyLevel * 1.5;
    }

    std::vector<Monster*> candidates = filterMonstersByChallenge(maxChallenge);

    if (candidates.empty())
    {
        std::cout << "No monsters available for this encounter.\n";
        return encounter;
    }

    int currentExperience = 0;

    while (currentExperience < budget)
    {
        int randomIndex = std::rand() % candidates.size();
        Monster* selectedMonster = candidates[randomIndex];

        if (selectedMonster == nullptr)
        {
            continue;
        }

        int monsterExperience = selectedMonster->calculateThreat();

        if (currentExperience + monsterExperience > budget && currentExperience > 0)
        {
            break;
        }

        encounter.addMonster(selectedMonster);
        currentExperience += monsterExperience;

        if (monsterExperience <= 0)
        {
            break;
        }
    }

    return encounter;
}

int EncounterGenerator::calculateExperienceBudget(
    int partyLevel,
    int partySize,
    const std::string& difficulty
) const
{
    int baseBudget = partyLevel * partySize * 10;

    if (difficulty == "easy")
    {
        return baseBudget;
    }

    if (difficulty == "medium")
    {
        return baseBudget * 2;
    }

    if (difficulty == "hard")
    {
        return baseBudget * 3;
    }

    if (difficulty == "deadly")
    {
        return baseBudget * 4;
    }

    return baseBudget * 2;
}

std::vector<Monster*> EncounterGenerator::filterMonstersByChallenge(double maxChallenge) const
{
    std::vector<Monster*> filteredMonsters;

    if (bestiary == nullptr)
    {
        return filteredMonsters;
    }

    const std::vector<Monster*>& monsters = bestiary->getMonsters();

    for (Monster* monster : monsters)
    {
        if (monster != nullptr && monster->getChallengeRating() <= maxChallenge)
        {
            filteredMonsters.push_back(monster);
        }
    }

    return filteredMonsters;
}