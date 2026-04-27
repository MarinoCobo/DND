#include "Serialization.h"

void to_json(json& j, const CastingTime& ct)
{
    j = json{
        {"amount", ct.getAmount()},
        {"unit", static_cast<int>(ct.getTimeUnit())}
    };
}

void from_json(const json& j, CastingTime& ct)
{
    ct = CastingTime(
        j.at("amount").get<int>(),
        static_cast<TimeUnit>(j.at("unit").get<int>())
    );
}

void to_json(json& j, const SpellDuration& sd)
{
    j = json{
        {"amount", sd.getAmount()},
        {"unit", static_cast<int>(sd.getTimeUnit())},
        {"requiresConcentration", sd.getRequiresConcentration()},
        {"isInstantaneous", sd.getIsInstantaneous()},
        {"isUntilDispelled", sd.getIsUntilDispelled()}
    };
}

void from_json(const json& j, SpellDuration& sd)
{
    sd = SpellDuration(
        j.at("amount").get<int>(),
        static_cast<TimeUnit>(j.at("unit").get<int>()),
        j.at("requiresConcentration").get<bool>(),
        j.at("isInstantaneous").get<bool>(),
        j.at("isUntilDispelled").get<bool>()
    );
}

void to_json(json& j, const Spell& s)
{
    j = json{
        {"name", s.getName()},
        {"level", s.getLevel()},
        {"school", static_cast<int>(s.getSchool())},
        {"castingTime", s.getCastingTime()},
        {"spellDuration", s.getSpellDuration()},
        {"description", s.getDescription()}
    };
}

void from_json(const json& j, Spell& s)
{
    s = Spell(
        j.at("name").get<std::string>(),
        j.at("level").get<int>(),
        static_cast<SpellSchool>(j.at("school").get<int>()),
        j.at("castingTime").get<CastingTime>(),
        j.at("spellDuration").get<SpellDuration>(),
        j.at("description").get<std::string>()
    );
}