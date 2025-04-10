#include <stddef.h>
#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/utils.h"

int show_character_class(Character *character) {
    switch (character->char_class) {
        case CLASS_WARRIOR:
            println("Warrior");
        break;
        case CLASS_MAGE:
            println("Mage");
        break;
        case CLASS_ARCHER:
            println("Archer");
        break;
        default:
            println("Undefined class!");
        break;
    }
    return 0;
}

static void setup_stats(Character *character) {
    switch (character->char_class) {
        case CLASS_WARRIOR:
            character->health  = 100.0f;
        character->attack  = 10.0f;
        character->defense = 15.0f;
        break;
        case CLASS_MAGE:
            character->health  = 80.0f;
        character->attack  = 20.0f;
        character->defense = 5.0f;
        break;
        case CLASS_ARCHER:
            character->health  = 90.0f;
        character->attack  = 18.0f;
        character->defense = 8.0f;
        break;
        default:
            character->health  = 150.0f;
        character->attack  = 10.0f;
        character->defense = 15.0f;
        break;
    }
}

int create_character(Character *character) {
    if (character == NULL)
        return -1;
    println("Welcome to character creation!");
    print("Enter your name: ");
    if (!read_string(character->name, sizeof(character->name))) {
        println("Error reading name.");
        return -1;
    }
    println("");
    println("Choose your class:");
    println("  1. Warrior");
    println("  2. Mage");
    println("  3. Archer");
    print("Enter your class choice: ");
    const int input = read_int();

    CharacterClass choice = input;
    if (choice < CLASS_WARRIOR || choice > CLASS_ARCHER) {
        println("Invalid class. Defaulting to Warrior.");
        choice = CLASS_WARRIOR;
    }

    character->char_class = choice;
    setup_stats(character);
    println("");
    print("Your chose ");
    show_character_class(character);
    print("!");
    println("");
    return 0;
}

int create_monster(Character *character) {
    strcpy(character->name, "MONSTER");
    character->char_class = NOT_DEFINED;
    character->health = (float)random_number(50,100);
    character->attack = (float)random_number(10,20);
    character->defense = (float)random_number(5,15);
    println("Monster created!");
    return 0;
}

int show_character_info(Character *character) {
    printf("Nome: %s\n", character->name);
    if (character->char_class != NOT_DEFINED) {
        show_character_class(character);
    }
    printf("PV: %.1f\n", character->health);
    printf("ATK: %.1f\n", character->attack);
    printf("DF: %.1f\n", character->defense);
    return 0;
}

float damage_calculator(const Character *attacker, const Character *defender) {
    return attacker->attack - defender->defense;
}
