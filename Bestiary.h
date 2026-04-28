#ifndef BESTIARIO_H
#define BESTIARIO_H

#include "Monster.h"
#include <vector>
#include <string>

class Bestiary
{
private:
    std::vector<Monster*> monsters;

public:
    ~Bestiary();

    void addMonster(Monster* monster);
    Monster* findMonsterByName(const std::string& name);
    bool deleteMonster(const std::string& name);
    const std::vector<Monster*>& getMonsters() const;
    void showAllMonsters() const;
    int getMonsterCount() const;
};

#endif