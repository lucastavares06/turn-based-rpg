#include "menu.h"
#include "../utils/utils.h"

char display_main_menu(void) {
    println("");
    println("Main Menu:");
    println("  1. Create Character");
    println("  2. Start Battle");
    println("  3. Exit");
    print("Enter your option: ");
    return read_digit_char();
}
