/****************************************************************************
 * [S]imulated [M]edieval [A]dventure multi[U]ser [G]ame      |   \\._.//   *
 * -----------------------------------------------------------|   (0...0)   *
 * SMAUG 1.8 (C) 1994, 1995, 1996, 1998  by Derek Snider      |    ).:.(    *
 * -----------------------------------------------------------|    {o o}    *
 * SMAUG code team: Thoric, Altrag, Blodkai, Narn, Haus,      |   / ' ' \   *
 * Scryn, Rennard, Swordbearer, Gorog, Grishnakh, Nivek,      |~'~.VxvxV.~'~*
 * Tricops, Fireblade, Edmond, Conran                         |             *
 * ------------------------------------------------------------------------ *
 * Merc 2.1 Diku Mud improvments copyright (C) 1992, 1993 by Michael        *
 * Chastain, Michael Quan, and Mitchell Tse.                                *
 * Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,          *
 * Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.     *
 * ------------------------------------------------------------------------ *
 *                           Mud constants module                           *
 ****************************************************************************/

#include <stdio.h>
#include "h/mud.h"

const char *const npc_race[MAX_NPC_RACE] = {
   // Playable races - MAX_RACE in mud.h must be raised before more can be added after r9.
   "human", "elf", "dwarf", "halfling", "pixie", "vampire", "half-ogre",       // 6 (start from 0)
   "half-orc", "half-troll", "half-elf", "gith", "drow", "sea-elf",            // 12
   "lizardman", "gnome", "r5", "r6", "r7", "r8", "r9",                         // 19

   // NPCs only
   "troll", "ant", "ape", "baboon", "bat", "bear", "bee",                      // 26
   "beetle", "boar", "bugbear", "cat", "dog", "dragon", "ferret", "fly",       // 34
   "gargoyle", "gelatin", "ghoul", "gnoll", "goblin", "golem",                 // 40
   "gorgon", "harpy", "hobgoblin", "kobold", "locust",                         // 45
   "lycanthrope", "minotaur", "mold", "mule", "neanderthal", "ooze", "orc",    // 52
   "rat", "rustmonster", "shadow", "shapeshifter", "shrew", "shrieker",        // 58
   "skeleton", "slime", "snake", "spider", "stirge", "thoul", "troglodyte",    // 65
   "undead", "wight", "wolf", "worm", "zombie", "bovine", "canine", "feline",  // 73
   "porcine", "mammal", "rodent", "avis", "reptile", "amphibian", "fish",      // 80
   "crustacean", "insect", "spirit", "magical", "horse", "animal", "humanoid", // 87
   "monster", "god", "???"                                                     // 90
};

const char *const npc_class[MAX_NPC_CLASS] = {
   "mage", "cleric", "thief", "warrior", "vampire", "druid", "ranger",
   "augurer", "paladin", "nephandi", "savage", "pc11", "pc12", "pc13",
   "pc14", "pc15", "pc16", "pc17", "pc18", "pc19",
   "baker", "butcher", "blacksmith", "mayor", "king", "queen"
};

/*
 * Attribute bonus tables.
 */
const struct str_app_type str_app[26] = {
   {-5, -4, 0, 0},   /* 0  */
   {-5, -4, 3, 1},   /* 1  */
   {-3, -2, 3, 2},
   {-3, -1, 10, 3},  /* 3  */
   {-2, -1, 25, 4},
   {-2, -1, 55, 5},  /* 5  */
   {-1, 0, 80, 6},
   {-1, 0, 90, 7},
   {0, 0, 100, 8},
   {0, 0, 100, 9},
   {0, 0, 115, 10},  /* 10  */
   {0, 0, 115, 11},
   {0, 0, 140, 12},
   {0, 0, 140, 13},  /* 13  */
   {0, 1, 170, 14},
   {1, 1, 170, 15},  /* 15  */
   {1, 2, 195, 16},
   {2, 3, 220, 22},
   {2, 4, 250, 25},  /* 18  */
   {3, 5, 400, 30},
   {3, 6, 500, 35},  /* 20  */
   {4, 7, 600, 40},
   {5, 7, 700, 45},
   {6, 8, 800, 50},
   {8, 10, 900, 55},
   {10, 12, 999, 60} /* 25   */
};

const struct int_app_type int_app[26] = {
   {3},  /*  0 */
   {5},  /*  1 */
   {7},
   {8},  /*  3 */
   {9},
   {10}, /*  5 */
   {11},
   {12},
   {13},
   {15},
   {17}, /* 10 */
   {19},
   {22},
   {25},
   {28},
   {31}, /* 15 */
   {34},
   {37},
   {40}, /* 18 */
   {44},
   {49}, /* 20 */
   {55},
   {60},
   {70},
   {85},
   {99}  /* 25 */
};

const struct wis_app_type wis_app[26] = {
   {0},  /*  0 */
   {0},  /*  1 */
   {0},
   {0},  /*  3 */
   {0},
   {1},  /*  5 */
   {1},
   {1},
   {1},
   {2},
   {2},  /* 10 */
   {2},
   {2},
   {2},
   {2},
   {3},  /* 15 */
   {3},
   {4},
   {5},  /* 18 */
   {5},
   {5},  /* 20 */
   {6},
   {6},
   {6},
   {6},
   {7}   /* 25 */
};

const struct dex_app_type dex_app[26] = {
   {60}, /* 0 */
   {50}, /* 1 */
   {50},
   {40},
   {30},
   {20}, /* 5 */
   {10},
   {0},
   {0},
   {0},
   {0},  /* 10 */
   {0},
   {0},
   {0},
   {0},
   {-10},   /* 15 */
   {-15},
   {-20},
   {-30},
   {-40},
   {-50},   /* 20 */
   {-60},
   {-75},
   {-90},
   {-105},
   {-120}   /* 25 */
};

const struct con_app_type con_app[26] = {
   {-4, 20},   /*  0 */
   {-3, 25},   /*  1 */
   {-2, 30},
   {-2, 35},   /*  3 */
   {-1, 40},
   {-1, 45},   /*  5 */
   {-1, 50},
   {0, 55},
   {0, 60},
   {0, 65},
   {0, 70}, /* 10 */
   {0, 75},
   {0, 80},
   {0, 85},
   {0, 88},
   {1, 90}, /* 15 */
   {2, 95},
   {2, 97},
   {3, 99}, /* 18 */
   {3, 99},
   {4, 99}, /* 20 */
   {4, 99},
   {5, 99},
   {6, 99},
   {7, 99},
   {8, 99}  /* 25 */
};

const struct cha_app_type cha_app[26] = {
   {-60},   /* 0 */
   {-50},   /* 1 */
   {-50},
   {-40},
   {-30},
   {-20},   /* 5 */
   {-10},
   {-5},
   {-1},
   {0},
   {0},  /* 10 */
   {0},
   {0},
   {0},
   {1},
   {5},  /* 15 */
   {10},
   {20},
   {30},
   {40},
   {50}, /* 20 */
   {60},
   {70},
   {80},
   {90},
   {99}  /* 25 */
};

/* Have to fix this up - not exactly sure how it works (Scryn) */
const struct lck_app_type lck_app[26] = {
   {60}, /* 0 */
   {50}, /* 1 */
   {50},
   {40},
   {30},
   {20}, /* 5 */
   {10},
   {0},
   {0},
   {0},
   {0},  /* 10 */
   {0},
   {0},
   {0},
   {0},
   {-10},   /* 15 */
   {-15},
   {-20},
   {-30},
   {-40},
   {-50},   /* 20 */
   {-60},
   {-75},
   {-90},
   {-105},
   {-120}   /* 25 */
};

const char *const attack_table[18] = {
   "hit",
   "slice", "stab", "slash", "whip", "claw",
   "blast", "pound", "crush", "grep", "bite",
   "pierce", "suction", "bolt", "arrow", "dart",
   "stone", "pea"
};

const char *s_blade_messages[24] = {
   "miss", "barely scratch", "scratch", "nick", "cut", "hit", "tear",
   "rip", "gash", "lacerate", "hack", "maul", "rend", "decimate",
   "_mangle_", "_devastate_", "_cleave_", "_butcher_", "DISEMBOWEL",
   "DISFIGURE", "GUT", "EVISCERATE", "* SLAUGHTER *", "*** ANNIHILATE ***"
};

const char *p_blade_messages[24] = {
   "misses", "barely scratches", "scratches", "nicks", "cuts", "hits",
   "tears", "rips", "gashes", "lacerates", "hacks", "mauls", "rends",
   "decimates", "_mangles_", "_devastates_", "_cleaves_", "_butchers_",
   "DISEMBOWELS", "DISFIGURES", "GUTS", "EVISCERATES", "* SLAUGHTERS *",
   "*** ANNIHILATES ***"
};

const char *s_blunt_messages[24] = {
   "miss", "barely scuff", "scuff", "pelt", "bruise", "strike", "thrash",
   "batter", "flog", "pummel", "smash", "maul", "bludgeon", "decimate",
   "_shatter_", "_devastate_", "_maim_", "_cripple_", "MUTILATE", "DISFIGURE",
   "MASSACRE", "PULVERIZE", "* OBLITERATE *", "*** ANNIHILATE ***"
};

const char *p_blunt_messages[24] = {
   "misses", "barely scuffs", "scuffs", "pelts", "bruises", "strikes",
   "thrashes", "batters", "flogs", "pummels", "smashes", "mauls",
   "bludgeons", "decimates", "_shatters_", "_devastates_", "_maims_",
   "_cripples_", "MUTILATES", "DISFIGURES", "MASSACRES", "PULVERIZES",
   "* OBLITERATES *", "*** ANNIHILATES ***"
};

const char *s_generic_messages[24] = {
   "miss", "brush", "scratch", "graze", "nick", "jolt", "wound",
   "injure", "hit", "jar", "thrash", "maul", "decimate", "_traumatize_",
   "_devastate_", "_maim_", "_demolish_", "MUTILATE", "MASSACRE",
   "PULVERIZE", "DESTROY", "* OBLITERATE *", "*** ANNIHILATE ***",
   "**** SMITE ****"
};

const char *p_generic_messages[24] = {
   "misses", "brushes", "scratches", "grazes", "nicks", "jolts", "wounds",
   "injures", "hits", "jars", "thrashes", "mauls", "decimates", "_traumatizes_",
   "_devastates_", "_maims_", "_demolishes_", "MUTILATES", "MASSACRES",
   "PULVERIZES", "DESTROYS", "* OBLITERATES *", "*** ANNIHILATES ***",
   "**** SMITES ****"
};

const char **const s_message_table[18] = {
   s_generic_messages,  /* hit */
   s_blade_messages, /* slice */
   s_blade_messages, /* stab */
   s_blade_messages, /* slash */
   s_blunt_messages, /* whip */
   s_blade_messages, /* claw */
   s_generic_messages,  /* blast */
   s_blunt_messages, /* pound */
   s_blunt_messages, /* crush */
   s_generic_messages,  /* grep */
   s_blade_messages, /* bite */
   s_blade_messages, /* pierce */
   s_blunt_messages, /* suction */
   s_generic_messages,  /* bolt */
   s_generic_messages,  /* arrow */
   s_generic_messages,  /* dart */
   s_generic_messages,  /* stone */
   s_generic_messages   /* pea */
};

const char **const p_message_table[18] = {
   p_generic_messages,  /* hit */
   p_blade_messages, /* slice */
   p_blade_messages, /* stab */
   p_blade_messages, /* slash */
   p_blunt_messages, /* whip */
   p_blade_messages, /* claw */
   p_generic_messages,  /* blast */
   p_blunt_messages, /* pound */
   p_blunt_messages, /* crush */
   p_generic_messages,  /* grep */
   p_blade_messages, /* bite */
   p_blade_messages, /* pierce */
   p_blunt_messages, /* suction */
   p_generic_messages,  /* bolt */
   p_generic_messages,  /* arrow */
   p_generic_messages,  /* dart */
   p_generic_messages,  /* stone */
   p_generic_messages   /* pea */
};

/* Weather constants - FB */
const char *const temp_settings[MAX_CLIMATE] = {
   "cold",
   "cool",
   "normal",
   "warm",
   "hot",
};

const char *const precip_settings[MAX_CLIMATE] = {
   "arid",
   "dry",
   "normal",
   "damp",
   "wet",
};

const char *const wind_settings[MAX_CLIMATE] = {
   "still",
   "calm",
   "normal",
   "breezy",
   "windy",
};

const char *const preciptemp_msg[6][6] = {
   /*
    * precip = 0 
    */
   {
    "Frigid temperatures settle over the land",
    "It is bitterly cold",
    "The weather is crisp and dry",
    "A comfortable warmth sets in",
    "A dry heat warms the land",
    "Seething heat bakes the land"},
   /*
    * precip = 1 
    */
   {
    "A few flurries drift from the high clouds",
    "Frozen drops of rain fall from the sky",
    "An occasional raindrop falls to the ground",
    "Mild drops of rain seep from the clouds",
    "It is very warm, and the sky is overcast",
    "High humidity intensifies the seering heat"},
   /*
    * precip = 2 
    */
   {
    "A brief snow squall dusts the earth",
    "A light flurry dusts the ground",
    "Light snow drifts down from the heavens",
    "A light drizzle mars an otherwise perfect day",
    "A few drops of rain fall to the warm ground",
    "A light rain falls through the sweltering sky"},
   /*
    * precip = 3 
    */
   {
    "Snowfall covers the frigid earth",
    "Light snow falls to the ground",
    "A brief shower moistens the crisp air",
    "A pleasant rain falls from the heavens",
    "The warm air is heavy with rain",
    "A refreshing shower eases the oppresive heat"},
   /*
    * precip = 4 
    */
   {
    "Sleet falls in sheets through the frosty air",
    "Snow falls quickly, piling upon the cold earth",
    "Rain pelts the ground on this crisp day",
    "Rain drums the ground rythmically",
    "A warm rain drums the ground loudly",
    "Tropical rain showers pelt the seering ground"},
   /*
    * precip = 5 
    */
   {
    "A downpour of frozen rain covers the land in ice",
    "A blizzard blankets everything in pristine white",
    "Torrents of rain fall from a cool sky",
    "A drenching downpour obscures the temperate day",
    "Warm rain pours from the sky",
    "A torrent of rain soaks the heated earth"}
};

const char *const windtemp_msg[6][6] = {
   /*
    * wind = 0 
    */
   {
    "The frigid air is completely still",
    "A cold temperature hangs over the area",
    "The crisp air is eerily calm",
    "The warm air is still",
    "No wind makes the day uncomfortably warm",
    "The stagnant heat is sweltering"},
   /*
    * wind = 1 
    */
   {
    "A light breeze makes the frigid air seem colder",
    "A stirring of the air intensifies the cold",
    "A touch of wind makes the day cool",
    "It is a temperate day, with a slight breeze",
    "It is very warm, the air stirs slightly",
    "A faint breeze stirs the feverish air"},
   /*
    * wind = 2 
    */
   {
    "A breeze gives the frigid air bite",
    "A breeze swirls the cold air",
    "A lively breeze cools the area",
    "It is a temperate day, with a pleasant breeze",
    "Very warm breezes buffet the area",
    "A breeze ciculates the sweltering air"},
   /*
    * wind = 3 
    */
   {
    "Stiff gusts add cold to the frigid air",
    "The cold air is agitated by gusts of wind",
    "Wind blows in from the north, cooling the area",
    "Gusty winds mix the temperate air",
    "Brief gusts of wind punctuate the warm day",
    "Wind attempts to cut the sweltering heat"},
   /*
    * wind = 4 
    */
   {
    "The frigid air whirls in gusts of wind",
    "A strong, cold wind blows in from the north",
    "Strong wind makes the cool air nip",
    "It is a pleasant day, with gusty winds",
    "Warm, gusty winds move through the area",
    "Blustering winds punctuate the seering heat"},
   /*
    * wind = 5 
    */
   {
    "A frigid gale sets bones shivering",
    "Howling gusts of wind cut the cold air",
    "An angry wind whips the air into a frenzy",
    "Fierce winds tear through the tepid air",
    "Gale-like winds whip up the warm air",
    "Monsoon winds tear the feverish air"}
};

const char *const precip_msg[3] = {
   "there is not a cloud in the sky",
   "pristine white clouds are in the sky",
   "thick, grey clouds mask the sun"
};

const char *const wind_msg[6] = {
   "there is not a breath of wind in the air",
   "a slight breeze stirs the air",
   "a breeze wafts through the area",
   "brief gusts of wind punctuate the air",
   "angry gusts of wind blow",
   "howling winds whip the air into a frenzy"
};
