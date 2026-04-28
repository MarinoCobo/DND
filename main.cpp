#include <iostream>
#include <string>
#include <limits>
#include "SpellBook.h"
#include "Spell.h"
#include "CastingTime.h"
#include "SpellDuration.h"
#include "DNDTypes.h"

SpellSchool getSpellSchoolFromUser()
{
    int option;

    std::cout << "Select the spell school:\n";
    std::cout << "1. Abjuration\n";
    std::cout << "2. Conjuration\n";
    std::cout << "3. Divination\n";
    std::cout << "4. Enchantment\n";
    std::cout << "5. Evocation\n";
    std::cout << "6. Illusion\n";
    std::cout << "7. Necromancy\n";
    std::cout << "8. Transmutation\n";
    std::cout << "Option: ";
    std::cin >> option;

    switch (option)
    {
        case 1: return SpellSchool::Abjuration;
        case 2: return SpellSchool::Conjuration;
        case 3: return SpellSchool::Divination;
        case 4: return SpellSchool::Enchantment;
        case 5: return SpellSchool::Evocation;
        case 6: return SpellSchool::Illusion;
        case 7: return SpellSchool::Necromancy;
        case 8: return SpellSchool::Transmutation;
        default:
            std::cout << "Invalid option. Defaulting to Abjuration.\n";
            return SpellSchool::Abjuration;
    }
}

TimeUnit getTimeUnitFromUser()
{
    int option;

    std::cout << "Select the time unit:\n";
    std::cout << "1. Action\n";
    std::cout << "2. Bonus Action\n";
    std::cout << "3. Reaction\n";
    std::cout << "4. Round\n";
    std::cout << "5. Minute\n";
    std::cout << "6. Hour\n";
    std::cout << "7. Day\n";
    std::cout << "8. Special\n";
    std::cout << "Option: ";
    std::cin >> option;

    switch (option)
    {
        case 1: return TimeUnit::Action;
        case 2: return TimeUnit::BonusAction;
        case 3: return TimeUnit::Reaction;
        case 4: return TimeUnit::Round;
        case 5: return TimeUnit::Minute;
        case 6: return TimeUnit::Hour;
        case 7: return TimeUnit::Day;
        case 8: return TimeUnit::Special;
        default:
            std::cout << "Invalid option. Defaulting to Action.\n";
            return TimeUnit::Action;
    }
}

void clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Spell createSpellFromUser()
{
    std::string name;
    int level;
    SpellSchool school;
    int castingAmount;
    TimeUnit castingUnit;
    int durationAmount;
    TimeUnit durationUnit;
    bool requiresConcentration;
    bool isInstantaneous;
    bool isUntilDispelled;
    std::string description;

    clearInputBuffer();

    std::cout << "Enter spell name: ";
    std::getline(std::cin, name);

    std::cout << "Enter spell level: ";
    std::cin >> level;

    school = getSpellSchoolFromUser();

    std::cout << "Enter casting time amount: ";
    std::cin >> castingAmount;
    castingUnit = getTimeUnitFromUser();

    std::cout << "Enter duration amount: ";
    std::cin >> durationAmount;
    durationUnit = getTimeUnitFromUser();

    std::cout << "Requires concentration? (1 = yes, 0 = no): ";
    std::cin >> requiresConcentration;

    std::cout << "Is instantaneous? (1 = yes, 0 = no): ";
    std::cin >> isInstantaneous;

    std::cout << "Is until dispelled? (1 = yes, 0 = no): ";
    std::cin >> isUntilDispelled;

    clearInputBuffer();

    std::cout << "Enter description: ";
    std::getline(std::cin, description);

    CastingTime castingTime(castingAmount, castingUnit);
    SpellDuration spellDuration(durationAmount, durationUnit, requiresConcentration, isInstantaneous, isUntilDispelled);

    return Spell(name, level, school, castingTime, spellDuration, description);
}

int main()
{
    SpellBook spellBook;
    const std::string filename = "SpellBook.json";
    int option = 0;

    do
    {
        std::cout << "\n===== SPELLBOOK MENU =====\n";
        std::cout << "1. Load spellbook from file\n";
        std::cout << "2. Add spell\n";
        std::cout << "3. Show all spells\n";
        std::cout << "4. Find spell by name\n";
        std::cout << "5. Delete spell by name\n";
        std::cout << "6. Save spellbook to file\n";
        std::cout << "7. Save and exit\n";
        std::cout << "0. Exit without saving\n";
        std::cout << "Option: ";
        std::cin >> option;

        switch (option)
        {
            case 1:
            {
                spellBook.loadFromFile(filename);
                std::cout << "Spellbook loaded from " << filename << ".\n";
                break;
            }

            case 2:
            {
                Spell newSpell = createSpellFromUser();
                spellBook.addSpell(newSpell);
                std::cout << "Spell added successfully.\n";
                break;
            }

            case 3:
            {
                std::cout << "Current spellbook:\n";
                spellBook.showAllSpells();
                break;
            }

            case 4:
            {
                std::string name;
                clearInputBuffer();
                std::cout << "Enter spell name to find: ";
                std::getline(std::cin, name);

                Spell* foundSpell = spellBook.findSpellByName(name);

                if (foundSpell != nullptr)
                {
                    foundSpell->displayInfo();
                }
                else
                {
                    std::cout << "Spell not found.\n";
                }
                break;
            }

            case 5:
            {
                std::string name;
                clearInputBuffer();
                std::cout << "Enter spell name to delete: ";
                std::getline(std::cin, name);

                if (spellBook.deleteSpell(name))
                {
                    std::cout << "Spell deleted successfully.\n";
                }
                else
                {
                    std::cout << "Spell not found.\n";
                }
                break;
            }

            case 6:
            {
                spellBook.saveToFile(filename);
                std::cout << "Spellbook saved to " << filename << ".\n";
                break;
            }

            case 7:
            {
                spellBook.saveToFile(filename);
                std::cout << "Spellbook saved. Exiting.\n";
                break;
            }

            case 0:
            {
                std::cout << "Exiting without saving.\n";
                break;
            }

            default:
            {
                std::cout << "Invalid option.\n";
                break;
            }
        }

    } while (option != 0 && option != 7);

    return 0;
}