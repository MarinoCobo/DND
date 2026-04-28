#include "Bestiary.h"
#include <iostream>


Bestiary::~Bestiary()
{
    for (Monster* monster : monsters)
    {
        delete monster;
    }

    monsters.clear();
}

void Bestiary::addMonster(Monster* monster)
{
    if (monster != nullptr)
    {
        monsters.push_back(monster);
    }
}

Monster* Bestiary::findMonsterByName(const std::string& name)
{
    for (Monster* monster : monsters)
    {
        if (monster != nullptr && monster->getName() == name)
        {
            return monster;
        }
    }

    return nullptr;
}

bool Bestiary::deleteMonster(const std::string& name)
{
    for (auto it = monsters.begin(); it != monsters.end(); ++it)
    {
        if (*it != nullptr && (*it)->getName() == name)
        {
            delete *it;
            monsters.erase(it);
            return true;
        }
    }

    return false;
}

void Bestiary::showAllMonsters() const
{
    if (monsters.empty())
    {
        std::cout << "No monsters in bestiary.\n";
        return;
    }

    for (const Monster* monster : monsters)
    {
        if (monster != nullptr)
        {
            monster->displayInfo();
            std::cout << "\n-----------------------------\n";
        }
    }
}

int Bestiary::getMonsterCount() const
{
    return static_cast<int>(monsters.size());
}