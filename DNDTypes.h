#ifndef DNDTYPES_H
#define DNDTYPES_H

enum class Ability {
    Strength,
    Dexterity,
    Constitution,
    Intelligence,
    Wisdom,
    Charisma,
    Count
};

enum class Skill {
    Acrobatics,
    AnimalHandling,
    Arcana,
    Athletics,
    Deception,
    History,
    Insight,
    Intimidation,
    Investigation,
    Medicine,
    Nature,
    Perception,
    Performance,
    Persuasion,
    Religion,
    SleightOfHand,
    Stealth,
    Survival,
    Count
};

enum class Size {
    Tiny,
    Small,
    Medium,
    Large,
    Huge,
    Gargantuan
};

enum class CreatureType {
    Aberration,
    Beast,
    Celestial,
    Construct,
    Dragon,
    Elemental,
    Fey,
    Fiend,
    Giant,
    Humanoid,
    Monstrosity,
    Ooze,
    Plant,
    Undead
};

enum class SpellSchool {
    Abjuration,
    Conjuration,
    Divination,
    Enchantment,
    Evocation,
    Illusion,
    Necromancy,
    Transmutation
};

enum class RechargeType {
    AtWill,
    Daily,
    ShortRest,
    LongRest,
    SpellSlot
};

enum class TimeUnit {
    Action,
    BonusAction,
    Reaction,
    Round,
    Minute,
    Hour,
    Day,
    Special
};

#endif