#include "menu.h"

#include <stdio.h>

#include "../utils/utils.h"

int display_main_menu() {
    println("");
    println("Main Menu:");
    println("  1. Create Character");
    println("  2. Start Battle");
    println("  3. Exit");
    print("Enter your option: ");

    return read_int();
}
