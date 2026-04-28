#ifndef BESTIARIO_H
#define BESTIARIO_H

#include "Monster.h"
#include <vector>
#include <string>

class Bestiario
{
private:
    std::vector<Monster*> monsters;

public:
    Bestiario();
    ~Bestiario();

    void addMonster(Monster* monster);
    Monster* findMonsterByName(const std::string& name);
    bool deleteMonster(const std::string& name);
    void showAllMonsters() const;
    int getMonsterCount() const;
};

#endif