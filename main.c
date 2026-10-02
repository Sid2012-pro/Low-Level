#include <stdio.h>
#include <string.h>

#define TOTAL_CARDS_IN_GAME 12
#define MAX_CARDS 10

struct Card {
    char name[32];
    int cost;
    int dmg;
    int catch_up;
    int sabotage;
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
    {.name = "Steel Ball", .cost = 1, .damage = 12, .catch_up = 0, .sabotage = 10, .target = "CLOSEST", .awaken = false, .awaken_chnc = 0},
    {.name = "Finger Gun", .cost = 3, .damage = 20, .catch_up = 0, .sabotage = 15, .target = "STRONGEST", .awaken = true, .awaken_chnc = 10 },
    {.name = "Tusk", .cost = 5, .damage = 50, .catch_up = 0, .sabotage = 40, .target = "CLOSEST", .awaken = true, .awaken_chnc = 30}
};