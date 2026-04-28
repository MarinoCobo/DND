#ifndef ENCOUNTERGENERATOR_H
#define ENCOUNTERGENERATOR_H

#include "Bestiary.h"
#include "Encounter.h"
#include "Monster.h"
#include <vector>
#include <string>

class EncounterGenerator
{
private:
    Bestiary* bestiary;

public:
    EncounterGenerator(Bestiary* bestiary);

    Encounter generateEncounter(int partyLevel, int partySize, const std::string& difficulty);

    int calculateExperienceBudget(int partyLevel, int partySize, const std::string& difficulty) const;

    std::vector<Monster*> filterMonstersByChallenge(double maxChallenge) const;
};

#endif