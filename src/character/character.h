#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdbool.h>

#define MAX_NAME_LENGTH 50

typedef enum {
    CLASS_WARRIOR = 1,
    CLASS_MAGE,
    CLASS_ARCHER,
    CLASS_MONSTER
} CharacterClass;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float health;
    float attack;
    float defense;

    float max_health;
    float base_attack;
    float base_defense;

    CharacterClass class;
} Character;

void create_player_character(Character *character);

void create_monster_character(Character *character);

bool show_character_info(const Character *character);

void reset_character_stats(Character *character);

#endif
