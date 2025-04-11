#include <menu.h>
#include <utils.h>

int display_main_menu(void) {
    println("\nMain Menu:");
    println("  1. Create Character");
    println("  2. Start Battle");
    println("  3. Exit");

    int option;
    do {
        print("Enter your option: ");
        option = read_int();
    } while (option < 1 || option > 3);

    return option;
}
