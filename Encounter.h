#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include "Monster.h"
#include <vector>
#include <string>

class Encounter
{
private:
    std::vector<Monster*> monsters;
    std::string difficulty;
    int totalExperience;

public:
    Encounter(const std::string& difficulty);

    void addMonster(Monster* monster);

    void showEncounter() const;

    int calculateTotalExperience();

    void clearEncounter();
};

#endif