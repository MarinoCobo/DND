#include "BasicMonster.h"

BasicMonster::BasicMonster(
    const std::string& name,
    int armorClass,
    int hitPoints,
    int walkSpeed,
    int flySpeed,
    int swimSpeed,
    Size size,
    CreatureType creatureType,
    double challengeRating
)
    : Monster(
        name,
        armorClass,
        hitPoints,
        walkSpeed,
        flySpeed,
        swimSpeed,
        size,
        creatureType,
        challengeRating
    )
{
}

int BasicMonster::calculateThreat() const
{
    return static_cast<int>(getChallengeRating() * 10 + getHitPoints() / 10 + getArmorClass());
}

Monster* BasicMonster::clone() const
{
    return new BasicMonster(*this);
}