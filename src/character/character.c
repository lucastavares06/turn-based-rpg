#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <terminal.h>
#include <utils.h>
#include <colors.h>
#include <character.h>

static void setup_stats(Character *character) {
    switch (character->class) {
        case CLASS_WARRIOR:
            character->health  = 100.0f;
            character->attack  = 12.0f;
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
        case CLASS_MONSTER:
            character->health  = random_float(50.0f, 150.0f);
            character->attack  = random_float(10.0f, 20.0f);
            character->defense = random_float(5.0f, 15.0f);
            break;
        default:
            println("[ERROR] Invalid character class in setup_stats");
            break;
    }
    character->max_health   = character->health;
    character->base_attack  = character->attack;
    character->base_defense = character->defense;
}

char *get_character_class_name(const CharacterClass class) {
    switch (class) {
        case CLASS_WARRIOR: return "Warrior";
        case CLASS_MAGE:    return "Mage";
        case CLASS_ARCHER:  return "Archer";
        case CLASS_MONSTER: return "Monster";
        default:            return "Undefined class";
    }
}

static void initialize_character(Character *character, const bool is_player) {
    memset(character, 0, sizeof(Character));

    if (is_player) {
        println("\nWelcome to character creation!");

        do {
            print("Enter your name: ");
            read_string(character->name, MAX_NAME_LENGTH);
        } while (character->name[0] == '\0');

        println("\nChoose your class:");
        println("  1. Warrior");
        println("  2. Mage");
        println("  3. Archer");

        int input;
        do {
            print("Enter your class choice: ");
            input = read_int();
        } while (input < CLASS_WARRIOR || input > CLASS_ARCHER);

        clear_screen();
        character->class = input;
    } else {
        safe_copy_string(character->name, "Monster", MAX_NAME_LENGTH);
        character->class = CLASS_MONSTER;
    }

    setup_stats(character);
}

void create_player_character(Character *character) {
    initialize_character(character, true);
}

void create_monster_character(Character *character) {
    initialize_character(character, false);
}

bool show_character_info(const Character *character) {
    println("");
    printf("%sName:%s %s\n", ANSI_COLOR_ORANGE, ANSI_COLOR_RESET, character->name);
    printf("%sClass:%s %s\n", ANSI_COLOR_ORANGE, ANSI_COLOR_RESET, get_character_class_name(character->class));
    printf("%sHP:%s %.1f\n", ANSI_COLOR_ORANGE, ANSI_COLOR_RESET, character->health);
    printf("%sATK:%s %.1f\n", ANSI_COLOR_ORANGE, ANSI_COLOR_RESET, character->attack);
    printf("%sDEF:%s %.1f\n", ANSI_COLOR_ORANGE, ANSI_COLOR_RESET, character->defense);
    println("");
    return true;
}

void reset_character_stats(Character *character) {
    character->health  = character->max_health;
    character->attack  = character->base_attack;
    character->defense = character->base_defense;
}
