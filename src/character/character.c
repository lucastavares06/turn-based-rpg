#include <stddef.h>
#include "character.h"
#include "../utils/utils.h"

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
    const char input = read_digit_char();
    CharacterClass choice = input - '0';
    if (choice < CLASS_WARRIOR || choice > CLASS_ARCHER) {
        println("Invalid class. Defaulting to Warrior.");
        choice = CLASS_WARRIOR;
    }
    character->char_class = choice;
    setup_stats(character);
    println("");
    switch (character->char_class) {
        case CLASS_WARRIOR:
            println("You chose Warrior!");
        break;
        case CLASS_MAGE:
            println("You chose Mage!");
        break;
        case CLASS_ARCHER:
            println("You chose Archer!");
        break;
        default:
            println("Undefined class!");
        break;
    }
    return 0;
}
