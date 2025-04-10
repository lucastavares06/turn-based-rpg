#include "game.h"
#include "../menu/menu.h"
#include "../character/character.h"
#include "../utils/utils.h"

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
                if (result == 0)
                    println("Character created successfully!");
                else
                    println("Error creating character.");
                break;
            case 2:
                println("Starting battle (under construction)...");
                int result = create_monster(&monster_character);
                if (result == 0)
                    show_character_info(&monster_character);
                else
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
