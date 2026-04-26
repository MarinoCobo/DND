#include <iostream>
#include <string>
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

int main()
{
    SpellBook spellBook;

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

    std::cin.ignore();

    std::cout << "Enter description: ";
    std::getline(std::cin, description);

    CastingTime castingTime(castingAmount, castingUnit);
    SpellDuration spellDuration(durationAmount, durationUnit, requiresConcentration, isInstantaneous, isUntilDispelled);

    Spell newSpell(name, level, school, castingTime, spellDuration, description);

    spellBook.addSpell(newSpell);

    std::cout << "\nSpell created successfully.\n\n";
    newSpell.displayInfo();

    std::cout << "\nCurrent spellbook:\n";
    spellBook.showAllSpells();

    return 0;
}