#include "SpellBook.h"
#include "serialization.h"
#include <iostream>
#include <fstream>

void SpellBook::addSpell(const Spell& spell)
{
    this->spellBook.push_back(spell);
}

Spell* SpellBook::findSpellByName(const std::string& name)
{
    for(size_t j = 0; j < this->spellBook.size(); j++)
    {
        if (spellBook[j].getName() == name)
        {
            return &spellBook[j];
        }
    }
    return nullptr;
}
void SpellBook::showAllSpells() const
{
    for(size_t j = 0; j < this->spellBook.size(); j++)
    {
        std::cout << spellBook[j].getName();
        if (j < this->spellBook.size() - 1)
        {
            std::cout << ", ";
        }
    } 
    std::cout << std::endl;
}
bool SpellBook::deleteSpell(const std::string& name)
{
    for(size_t j = 0; j < this->spellBook.size(); j++)
    {
        if (spellBook[j].getName() == name)
        {
            spellBook.erase(spellBook.begin() + j);
            return true;
        }
    } 
    return false;
}
void SpellBook::saveToFile(const std::string& filename) const
{
    json data;
    data["spells"] = json::array();

    for (const Spell& spell : spellBook)
    {
        data["spells"].push_back(spell);
    }

    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error: no se pudo abrir el archivo para guardar.\n";
        return;
    }

    file << data.dump(4);
    file.close();
}
void SpellBook::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error: no se pudo abrir el archivo para cargar.\n";
        return;
    }

    json data;
    file >> data;
    file.close();

    spellBook.clear();

    for (const json& spellJson : data["spells"])
    {
        const json& castingTimeJson = spellJson.at("castingTime");
        CastingTime castingTime(
            castingTimeJson.at("amount").get<int>(),
            static_cast<TimeUnit>(castingTimeJson.at("unit").get<int>())
        );

        const json& spellDurationJson = spellJson.at("spellDuration");
        SpellDuration spellDuration(
            spellDurationJson.at("amount").get<int>(),
            static_cast<TimeUnit>(spellDurationJson.at("unit").get<int>()),
            spellDurationJson.at("requiresConcentration").get<bool>(),
            spellDurationJson.at("isInstantaneous").get<bool>(),
            spellDurationJson.at("isUntilDispelled").get<bool>()
        );

        Spell spell(
            spellJson.at("name").get<std::string>(),
            spellJson.at("level").get<int>(),
            static_cast<SpellSchool>(spellJson.at("school").get<int>()),
            castingTime,
            spellDuration,
            spellJson.at("description").get<std::string>()
        );

        spellBook.push_back(spell);
    }
}