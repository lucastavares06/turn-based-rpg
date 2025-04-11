#include <menu.h>
#include <character.h>
#include <terminal.h>
#include <utils.h>
#include <battle.h>
#include <colors.h>
#include <game.h>
#include <stdio.h>

static void handle_create_character(Character *player) {
    clear_screen();
    create_player_character(player);
    show_character_info(player);
    printf("%sCharacter created successfully!%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
}

static void handle_start_battle(Character *player) {
    if (!player->name[0] || player->health <= 0) {
        println("\nYour character is dead or not created. Create a new one first.");
        return;
    }

    player->health = player->max_health;

    Character monster;
    create_monster_character(&monster);
    start_battle(player, &monster);
}

int game_run(void) {
    seed_random();
    int option;
    Character player = {0};

    do {
        option = display_main_menu();
        switch (option) {
            case 1:
                handle_create_character(&player);
            break;
            case 2:
                handle_start_battle(&player);
            break;
            case 3:
                println("Exiting game...");
            break;
            default:
                break;
        }
    } while (option != 3);

    return 0;
}
