#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TOTAL_CARDS_IN_GAME 35
#define MAX_CARDS 10

typedef enum{
    CARD_MANEUVER,
    CARD_CONSUMABLE,
    CARD_COMBAT
} CardType;


struct Card {
    char name[32];
    CardType type;
    int cost;
    int dmg;
    int catch_up;
    int sabotage;
    int sustenance;
    char target[32];
    bool awaken;
    int awaken_chnc;
};

struct Player {
    char name[32]
    int rider_hp;
    int horse_hp;
    int hygiene;
    int thirst;
    int hunger;
    struct Card hand[MAX_CARDS];
    int hand_count;
};

struct Card CARD_DATABASE[TOTAL_CARDS_IN_GAME] = {
    //combat
{.name = "Steel Ball",       .type = CARD_COMBAT, .cost = 1, .dmg = 12, .catch_up = 0, .sabotage = 10, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Finger Gun",       .type = CARD_COMBAT, .cost = 3, .dmg = 20, .catch_up = 0, .sabotage = 15, .sustenance = 0, .target = "STRONGEST", .awaken = true,  .awaken_chnc = 10},
    {.name = "Tusk",             .type = CARD_COMBAT, .cost = 5, .dmg = 50, .catch_up = 0, .sabotage = 40, .sustenance = 0, .target = "CLOSEST",   .awaken = true,  .awaken_chnc = 30},
    {.name = "Scary Monsters",   .type = CARD_COMBAT, .cost = 3, .dmg = 28, .catch_up = 0, .sabotage = 20, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Fossil Transform", .type = CARD_COMBAT, .cost = 2, .dmg = 18, .catch_up = 0, .sabotage = 30, .sustenance = 0, .target = "WEAKEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Sand Dash Strike", .type = CARD_COMBAT, .cost = 2, .dmg = 22, .catch_up = 0, .sabotage = 10, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "In a Silent Way",  .type = CARD_COMBAT, .cost = 4, .dmg = 38, .catch_up = 0, .sabotage = 25, .sustenance = 0, .target = "ALL",       .awaken = false, .awaken_chnc = 0},
    {.name = "Wrecking Ball",    .type = CARD_COMBAT, .cost = 3, .dmg = 26, .catch_up = 0, .sabotage = 35, .sustenance = 0, .target = "STRONGEST", .awaken = false, .awaken_chnc = 0},
    {.name = "Left Hemisphere",  .type = CARD_COMBAT, .cost = 4, .dmg = 32, .catch_up = 0, .sabotage = 50, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Cream Starter",    .type = CARD_COMBAT, .cost = 2, .dmg = 15, .catch_up = 0, .sabotage = 15, .sustenance = 0, .target = "WEAKEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Flesh Spray",      .type = CARD_COMBAT, .cost = 3, .dmg = 24, .catch_up = 0, .sabotage = 20, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Mandom Rewind",    .type = CARD_COMBAT, .cost = 4, .dmg = 10, .catch_up = 0, .sabotage = 60, .sustenance = 0, .target = "ALL",       .awaken = false, .awaken_chnc = 0},
    {.name = "Catch the Rainbow",.type = CARD_COMBAT, .cost = 3, .dmg = 30, .catch_up = 0, .sabotage = 20, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Raindrop Blades",  .type = CARD_COMBAT, .cost = 2, .dmg = 16, .catch_up = 0, .sabotage = 15, .sustenance = 0, .target = "ALL",       .awaken = false, .awaken_chnc = 0},
    {.name = "Tomb of the Boom", .type = CARD_COMBAT, .cost = 2, .dmg = 14, .catch_up = 0, .sabotage = 25, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Iron Shrapnel",    .type = CARD_COMBAT, .cost = 3, .dmg = 22, .catch_up = 0, .sabotage = 30, .sustenance = 0, .target = "STRONGEST", .awaken = false, .awaken_chnc = 0},
    {.name = "Chocolate Disco",  .type = CARD_COMBAT, .cost = 3, .dmg = 25, .catch_up = 0, .sabotage = 40, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Wire Trap",        .type = CARD_COMBAT, .cost = 1, .dmg = 10, .catch_up = 0, .sabotage = 20, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},

    //maneuvres
};