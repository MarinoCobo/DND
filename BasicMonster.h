#ifndef BASICMONSTER_H
#define BASICMONSTER_H
#include "Monster.h"
#include <string>

class BasicMonster : public Monster
{
public:
    BasicMonster(
        const std::string& name,
        int armorClass,
        int hitPoints,
        int walkSpeed,
        int flySpeed,
        int swimSpeed,
        Size size,
        CreatureType creatureType,
        double challengeRating
    );

    int calculateThreat() const override;
    Monster* clone() const override;
};

#endif