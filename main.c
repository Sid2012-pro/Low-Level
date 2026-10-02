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
    {.name = "Steel Ball", .type = CARD_COMBAT, .cost = 1, .damage = 12, .catch_up = 0, .sabotage = 10, .target = "CLOSEST", .awaken = false, .awaken_chnc = 0},
    {.name = "Finger Gun", .type = CARD_COMBAT, .cost = 3, .damage = 20, .catch_up = 0, .sabotage = 15, .target = "STRONGEST", .awaken = true, .awaken_chnc = 10 },
    {.name = "Tusk", .type = CARD_COMBAT, .cost = 5, .damage = 50, .catch_up = 0, .sabotage = 40, .target = "CLOSEST", .awaken = true, .awaken_chnc = 30},
    {.name = "Scary Monsters", .type = CARD_COMBAT, .cost = 3, .dmg = 28, .catch_up = 0, .sabotage = 20, .target = "CLOSEST", .awaken = false, .awaken_chnc = 0},
    {.name = "Fossil Transform", .type = CARD_COMBAT, .cost = 2, .dmg = 18, catch_up = 0, },
    {.name = "Sand Dash Strike", .type = CARD_COMBAT, .cost = 2, .dmg = 22, .catch_up = 0, },
    {.name = "In a Silent Way", .type = CARD_COMBAT, .cost = 4, .dmg = 38, .catch_up = 0,}
    {.name = "Wrecking Ball", .type = CARD_COMBAT},
    {.name = "Left Hemisphere", .type= CARD_COMBAT},
    {.name = "Cream Starter", .type = CARD_COMBAT}

};