#include <iostream>
#include <string>
#include <limits>
#include "SpellBook.h"
#include "Spell.h"
#include "CastingTime.h"
#include "SpellDuration.h"
#include "DNDTypes.h"
#include "BasicMonster.h"
#include "MagicalMonster.h"
#include "Bestiary.h"
#include "Encounter.h"
#include "EncounterGenerator.h"

void clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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

void seedBestiary(Bestiary& bestiary)
{
    if (bestiary.getMonsterCount() > 0)
    {
        return;
    }

    BasicMonster* goblin = new BasicMonster(
        "Goblin",
        15,
        7,
        30,
        0,
        0,
        Size::Small,
        CreatureType::Humanoid,
        0.25
    );

    goblin->addTrait("Nimble Escape", "The goblin can take the Disengage or Hide action as a bonus action.");
    goblin->addAction("Scimitar", "Melee weapon attack with a curved blade.");
    goblin->addAction("Shortbow", "Ranged weapon attack with a shortbow.");
    goblin->addLanguage("Common");
    goblin->addLanguage("Goblin");

    BasicMonster* wolf = new BasicMonster(
        "Wolf",
        13,
        11,
        40,
        0,
        0,
        Size::Medium,
        CreatureType::Beast,
        0.25
    );

    wolf->addTrait("Keen Hearing and Smell", "The wolf has advantage on Wisdom checks that rely on hearing or smell.");
    wolf->addAction("Bite", "Melee weapon attack. The target may be knocked prone.");
    wolf->addSense("Passive Perception 13");

    MagicalMonster* cultMage = new MagicalMonster(
        "Cult Mage",
        12,
        40,
        30,
        0,
        0,
        Size::Medium,
        CreatureType::Humanoid,
        2.0,
        Ability::Intelligence,
        13,
        5
    );

    cultMage->addAction("Dagger", "Melee or ranged weapon attack with a dagger.");
    cultMage->addTrait("Dark Devotion", "The mage has advantage on saving throws against being charmed or frightened.");
    cultMage->addLanguage("Common");
    cultMage->addLanguage("Infernal");

    bestiary.addMonster(goblin);
    bestiary.addMonster(wolf);
    bestiary.addMonster(cultMage);
}

void showMainMenu()
{
    std::cout << "\n===== DND ENCOUNTER GENERATOR =====\n";
    std::cout << "1. Load spellbook from file\n";
    std::cout << "2. Add spell\n";
    std::cout << "3. Show all spells\n";
    std::cout << "4. Find spell by name\n";
    std::cout << "5. Delete spell by name\n";
    std::cout << "6. Save spellbook to file\n";
    std::cout << "7. Show bestiary\n";
    std::cout << "8. Find monster by name\n";
    std::cout << "9. Generate encounter\n";
    std::cout << "10. Show monster count\n";
    std::cout << "11. Save spellbook and exit\n";
    std::cout << "0. Exit without saving\n";
    std::cout << "Option: ";
}

int main()
{
    SpellBook spellBook;
    Bestiary bestiary;
    const std::string filename = "SpellBook.json";

    seedBestiary(bestiary);

    EncounterGenerator encounterGenerator(&bestiary);

    int option = 0;

    do
    {
        showMainMenu();
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
                bestiary.showAllMonsters();
                break;
            }

            case 8:
            {
                std::string name;
                clearInputBuffer();
                std::cout << "Enter monster name to find: ";
                std::getline(std::cin, name);

                Monster* foundMonster = bestiary.findMonsterByName(name);

                if (foundMonster != nullptr)
                {
                    foundMonster->displayInfo();
                }
                else
                {
                    std::cout << "Monster not found.\n";
                }
                break;
            }

            case 9:
            {
                int partyLevel;
                int partySize;
                std::string difficulty;

                std::cout << "Enter party level: ";
                std::cin >> partyLevel;

                std::cout << "Enter party size: ";
                std::cin >> partySize;

                std::cout << "Enter difficulty (easy, medium, hard, deadly): ";
                std::cin >> difficulty;

                Encounter encounter = encounterGenerator.generateEncounter(partyLevel, partySize, difficulty);
                encounter.showEncounter();
                break;
            }

            case 10:
            {
                std::cout << "Monsters in bestiary: " << bestiary.getMonsterCount() << std::endl;
                break;
            }

            case 11:
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

    } while (option != 0 && option != 11);

    return 0;
}