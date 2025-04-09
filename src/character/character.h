#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_NAME_LENGTH 50

typedef enum {
    CLASS_WARRIOR = 1,
    CLASS_MAGE,
    CLASS_ARCHER
} CharacterClass;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float health;
    float attack;
    float defense;
    CharacterClass char_class;
} Character;

int create_character(Character *character);

#endif
