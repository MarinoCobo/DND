#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include "include/json.hpp"
#include "CastingTime.h"
#include "SpellDuration.h"
#include "Spell.h"

using json = nlohmann::json;

void to_json(json& j, const CastingTime& ct);
void from_json(const json& j, CastingTime& ct);

void to_json(json& j, const SpellDuration& sd);
void from_json(const json& j, SpellDuration& sd);

void to_json(json& j, const Spell& s);
void from_json(const json& j, Spell& s);

#endif