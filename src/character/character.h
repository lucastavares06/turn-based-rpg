#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_NAME_LENGTH 50

typedef enum {
    CLASS_WARRIOR = 1,
    CLASS_MAGE,
    CLASS_ARCHER,
    NOT_DEFINED
} CharacterClass;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float health;
    float attack;
    float defense;
    CharacterClass char_class;
} Character;

int create_character(Character *character);

int create_monster(Character *character);

/**
 * Show character information
 * @param character
 */
int show_character_info(Character *character);

int show_character_class(Character *character);

#endif
