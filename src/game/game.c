#include "game.h"

#include <stdio.h>

#include "../menu/menu.h"
#include "../character/character.h"
#include "../utils/utils.h"

int start_battle(Character *character, Character *monster);
int fight(Character *attacker, Character *defender);
int finish(Character *character);

int game_run(void) {
    int option;
    Character main_character;
    Character monster_character;
    int result;

    do {
        option = display_main_menu();
        switch (option) {
            case 1:
                println("Creating character...");
            result = create_character(&main_character);
            if (result == 0){
                show_character_info(&main_character);
                println("Character created successfully!");
            }else
                    println("Error creating character.");
                break;
            case 2:
                println("Starting battle (under construction)...");
                result = create_monster(&monster_character);
                if (result == 0) {
                    show_character_info(&monster_character);
                    start_battle(&main_character, &monster_character);
                }else
                    println("Error creating character.");
                break;
            break;
            case 3:
                println("Exiting game...");
            break;
            default:
                println("Invalid option. Try again.");
            break;
        }
    } while (option != 3);
    return 0;
}

int start_battle(Character *character, Character *monster) {
    int round = 1;
    println("");
    println("=== Begin of Battle ===");

    while (character->health > 0 && monster->health > 0) {
        int result = 0;
        printf("Round %d:\n", round);
        result = fight(character, monster);
        if (result == 1) {
            finish(character);
        }
        result = fight(monster, character);
        if (result == 1) {
            finish(monster);
        }
        round++;
    }
    return 0;
}

int fight(Character *attacker, Character *defender) {
    printf("%s attacks  %s\n", attacker->name, defender->name);
    float dano = damage_calculator(attacker, defender);
    printf("Damage caused: %.1f\n", dano);
    defender->health -= dano;
    printf("PV do %s: %.1f\n",defender->name, defender->health);
    if (defender->health <= 0) {
        return 1;
    }
    println("");
    return 0;
}

int finish(Character *character) {
    println("=== End of Battle ===");
    if (character->char_class != NOT_DEFINED) {
        println("Congratulations! You killed the monster!");
    }else {
        println("FAZ O L");
    }
    return 0;
}
