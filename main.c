#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARDS_IN_GAME 35
#define MAX_CARDS 10
#define MAX_ENEMIES 3

typedef enum {
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
    char name[32];
    int rider_hp;
    int horse_hp;
    int hygiene;
    int thirst;
    int hunger;
    int energy;
    int distance;
    struct Card hand[MAX_CARDS];
    int hand_count;
};

struct Enemy {
    char name[32];
    int hp;
    int distance;
    bool active;
};

struct Card CARD_DATABASE[TOTAL_CARDS_IN_GAME] = {
    // combat
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

    // maneuvers
    {.name = "Spur Ahead",       .type = CARD_MANEUVER, .cost = 1, .dmg = 0,  .catch_up = 15, .sabotage = 0,  .sustenance = 0, .target = "SELF",      .awaken = false, .awaken_chnc = 0},
    {.name = "Drafting",         .type = CARD_MANEUVER, .cost = 1, .dmg = 0,  .catch_up = 25, .sabotage = 5,  .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Shortcut Rush",    .type = CARD_MANEUVER, .cost = 2, .dmg = 0,  .catch_up = 40, .sabotage = 0,  .sustenance = 0, .target = "SELF",      .awaken = false, .awaken_chnc = 0},
    {.name = "Whip Sprint",      .type = CARD_MANEUVER, .cost = 3, .dmg = 0,  .catch_up = 60, .sabotage = 10, .sustenance = 0, .target = "SELF",      .awaken = false, .awaken_chnc = 0},
    {.name = "Mud Throw",        .type = CARD_MANEUVER, .cost = 1, .dmg = 0,  .catch_up = 5,  .sabotage = 20, .sustenance = 0, .target = "CLOSEST",   .awaken = false, .awaken_chnc = 0},
    {.name = "Spike Caltrops",   .type = CARD_MANEUVER, .cost = 2, .dmg = 5,  .catch_up = 10, .sabotage = 35, .sustenance = 0, .target = "ALL",       .awaken = false, .awaken_chnc = 0},
    {.name = "Rein Cut",         .type = CARD_MANEUVER, .cost = 2, .dmg = 0,  .catch_up = 15, .sabotage = 45, .sustenance = 0, .target = "STRONGEST", .awaken = false, .awaken_chnc = 0},
    {.name = "Dust Cloud",       .type = CARD_MANEUVER, .cost = 1, .dmg = 0,  .catch_up = 10, .sabotage = 25, .sustenance = 0, .target = "ALL",       .awaken = false, .awaken_chnc = 0},

    // consumables
    {.name = "Water Canteen",    .type = CARD_CONSUMABLE, .cost = 1, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 15, .target = "SELF", .awaken = false, .awaken_chnc = 0},
    {.name = "Dried Jerky",      .type = CARD_CONSUMABLE, .cost = 1, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 20, .target = "SELF", .awaken = false, .awaken_chnc = 0},
    {.name = "Hot Coffee",       .type = CARD_CONSUMABLE, .cost = 2, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 30, .target = "SELF", .awaken = false, .awaken_chnc = 0},
    {.name = "Fresh Bread",      .type = CARD_CONSUMABLE, .cost = 1, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 25, .target = "SELF", .awaken = false, .awaken_chnc = 0},
    {.name = "Bourbon Bottle",   .type = CARD_CONSUMABLE, .cost = 2, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 40, .target = "SELF", .awaken = false, .awaken_chnc = 0},
    {.name = "Corpse Right Eye", .type = CARD_CONSUMABLE, .cost = 3, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 60, .target = "SELF", .awaken = true,  .awaken_chnc = 25},
    {.name = "Corpse Left Arm",  .type = CARD_CONSUMABLE, .cost = 3, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 60, .target = "SELF", .awaken = true,  .awaken_chnc = 25},
    {.name = "Corpse Spine",     .type = CARD_CONSUMABLE, .cost = 4, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 80, .target = "SELF", .awaken = true,  .awaken_chnc = 40},
    {.name = "Corpse Heart",     .type = CARD_CONSUMABLE, .cost = 5, .dmg = 0, .catch_up = 0, .sabotage = 0, .sustenance = 100,.target = "SELF", .awaken = true,  .awaken_chnc = 50}
};

void draw_card(struct Player *p) {
    if (p->hand_count < MAX_CARDS) {
        int random_index = rand() % TOTAL_CARDS_IN_GAME;
        p->hand[p->hand_count] = CARD_DATABASE[random_index];
        p->hand_count++;
    }
}

int find_target(struct Player *p, struct Enemy enemies[], int enemy_count, const char *target_type) {
    int target_idx = -1;

    if (strcmp(target_type, "CLOSEST") == 0) {
        int min_dist = 99999;
        for (int i = 0; i < enemy_count; i++) {
            if (!enemies[i].active) continue;
            int diff = abs(p->distance - enemies[i].distance);
            if (diff < min_dist) {
                min_dist = diff;
                target_idx = i;
            }
        }
    } else if (strcmp(target_type, "STRONGEST") == 0) {
        int max_hp = -1;
        for (int i = 0; i < enemy_count; i++) {
            if (!enemies[i].active) continue;
            if (enemies[i].hp > max_hp) {
                max_hp = enemies[i].hp;
                target_idx = i;
            }
        }
    } else if (strcmp(target_type, "WEAKEST") == 0) {
        int min_hp = 99999;
        for (int i = 0; i < enemy_count; i++) {
            if (!enemies[i].active) continue;
            if (enemies[i].hp < min_hp) {
                min_hp = enemies[i].hp;
                target_idx = i;
            }
        }
    }

    return target_idx;
}

void play_card(struct Player *p, struct Enemy enemies[], int enemy_count, int card_index) {
    if (card_index < 0 || card_index >= p->hand_count) return;

    struct Card c = p->hand[card_index];
    if (p->energy < c.cost) {
        printf("\nNot enough energy to play %s!\n", c.name);
        return;
    }

    p->energy -= c.cost;
    printf("\nPlayed: %s!\n", c.name);

    if (strcmp(c.target, "ALL") == 0) {
        for (int i = 0; i < enemy_count; i++) {
            if (!enemies[i].active) continue;
            if (c.dmg > 0) {
                enemies[i].hp -= c.dmg;
                printf(" -> Dealt %d damage to %s!\n", c.dmg, enemies[i].name);
            }
            if (c.sabotage > 0) {
                enemies[i].distance -= c.sabotage;
                printf(" -> Sabotaged %s! (-%d distance)\n", enemies[i].name, c.sabotage);
            }
            if (enemies[i].hp <= 0) {
                enemies[i].active = false;
                printf(" -> %s HAS BEEN ELIMINATED!\n", enemies[i].name);
            }
        }
    } else if (c.type == CARD_CONSUMABLE) {
        p->thirst += c.sustenance;
        p->hunger += c.sustenance;
        if (p->thirst > 100) p->thirst = 100;
        if (p->hunger > 100) p->hunger = 100;
        printf(" -> Restored %d sustenance (Thirst: %d | Hunger: %d)!\n", c.sustenance, p->thirst, p->hunger);
    } else {
        int target_idx = find_target(p, enemies, enemy_count, c.target);
        if (target_idx != -1) {
            struct Enemy *t = &enemies[target_idx];
            if (c.dmg > 0) {
                t->hp -= c.dmg;
                printf(" -> Dealt %d damage to %s (%s target)!\n", c.dmg, t->name, c.target);
            }
            if (c.sabotage > 0) {
                t->distance -= c.sabotage;
                printf(" -> Sabotaged %s! (-%d distance)\n", t->name, c.sabotage);
            }
            if (t->hp <= 0) {
                t->active = false;
                printf(" -> %s HAS BEEN ELIMINATED!\n", t->name);
            }
        } else {
            printf(" -> No valid target found!\n");
        }
    }

    if (c.type == CARD_MANEUVER && c.catch_up > 0) {
        p->distance += c.catch_up;
        printf(" -> Gained %d race distance!\n", c.catch_up);
    }

    for (int i = card_index; i < p->hand_count - 1; i++) {
        p->hand[i] = p->hand[i + 1];
    }
    p->hand_count--;
}

void process_turn_start(struct Player *p) {
    p->hunger -= 5;
    p->thirst -= 5;

    if (p->hunger < 0) p->hunger = 0;
    if (p->thirst < 0) p->thirst = 0;

    printf("\n[STATUS EFFECT] Sustenance decayed! (Hunger: %d | Thirst: %d)\n", p->hunger, p->thirst);

    if (p->hunger == 0 || p->thirst == 0) {
        p->rider_hp -= 10;
        printf("[WARNING] Starvation/Dehydration! Took 10 damage to Rider HP!\n");
    }
}

int main() {
    srand((unsigned int)time(NULL));

    struct Player p = {
        .name = "Gyro Zeppeli",
        .rider_hp = 100,
        .horse_hp = 100,
        .hygiene = 100,
        .thirst = 60,
        .hunger = 60,
        .energy = 5,
        .distance = 0,
        .hand_count = 0
    };

    struct Enemy enemies[MAX_ENEMIES] = {
        { .name = "Diego Brando", .hp = 80, .distance = 25, .active = true },
        { .name = "Sandman",      .hp = 60, .distance = 15, .active = true },
        { .name = "Wekapipo",     .hp = 70, .distance = 40, .active = true }
    };

    for (int i = 0; i < 5; i++) {
        draw_card(&p);
    }

    int choice;
    while (p.rider_hp > 0) {
        bool any_active = false;
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].active) any_active = true;
        }
        if (!any_active) break;

        printf("\n=========================================\n");
        printf("RIDER: %s | HP: %d | ENERGY: %d | DISTANCE: %d\n", p.name, p.rider_hp, p.energy, p.distance);
        printf("HUNGER: %d/100 | THIRST: %d/100\n", p.hunger, p.thirst);
        printf("-----------------------------------------\n");
        printf("RACE FOES:\n");
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].active) {
                printf(" - %s | HP: %d | DISTANCE: %d\n", enemies[i].name, enemies[i].hp, enemies[i].distance);
            } else {
                printf(" - %s | [RETIRED]\n", enemies[i].name);
            }
        }
        printf("=========================================\n");

        printf("Your Hand:\n");
        for (int i = 0; i < p.hand_count; i++) {
            printf(" [%d] %s (Cost: %d, Type: %d, Target: %s)\n", 
                   i + 1, p.hand[i].name, p.hand[i].cost, p.hand[i].type, p.hand[i].target);
        }
        printf(" [0] End Turn / Advance Race\n");
        printf("Select action: ");
        scanf("%d", &choice);

        if (choice == 0) {
            process_turn_start(&p);
            p.energy = 5;
            draw_card(&p);
        } else {
            play_card(&p, enemies, MAX_ENEMIES, choice - 1);
        }
    }

    if (p.rider_hp <= 0) {
        printf("\n*** RETIRED FROM THE STAGE... ***\n");
    } else {
        printf("\n*** VICTORY! All rival racers eliminated! ***\n");
    }

    return 0;
}