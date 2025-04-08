#include "utils/utils.h"

int main(void) {
    println("This is a turn based RPG");

    char selected_option;

    do {
        println("");
        println("1. Create character");
        println("2. Start battle");
        println("3. Exit");
        print("Enter your choice: ");

        selected_option = read_digit_char();

        switch (selected_option) {
            case '1':
                println("You chose to create a character.");
            // TO DO
            break;
            case '2':
                println("You chose to start a battle.");
            // TO DO
            break;
            case '3':
                println("Exiting the game.");
            break;
            default:
                println("Invalid option. Try again.");
        }
    } while (selected_option != '3');

    return 0;
}
