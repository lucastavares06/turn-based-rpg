#include "menu.h"
#include "../utils/utils.h"
#include "../character/character.h"

int run_game_menu(void) {
    char option;
    Character main_character;
    do {
        println("");
        println("Main Menu:");
        println("  1. Create Character");
        println("  2. Start Battle");
        println("  3. Exit");
        print("Enter your option: ");
        option = read_digit_char();
        switch (option) {
            case '1':
                println("Creating character...");
            if (create_character(&main_character) == 0)
                println("Character created successfully!");
            else
                println("Error creating character.");
            break;
            case '2':
                println("Starting battle (under construction)...");
            break;
            case '3':
                println("Exiting game...");
            break;
            default:
                println("Invalid option. Try again.");
            break;
        }
    } while (option != '3');
    return 0;
}
