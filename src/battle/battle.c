#include <utils.h>
#include <colors.h>
#include <terminal.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>
#include <battle.h>

bool is_character_alive(const Character *character)
{
    return character && character->health > 0.0f;
}

static void typewriter_print(const char *text)
{
    for (const char *p = text; *p; ++p) {
        putchar(*p);
        fflush(stdout);
        usleep(50000);
    }
}

static void print_health_bar(const float current_health, const float max_health)
{
    const int bar_width = 20;

    if (max_health <= 0.0f) {
        printf("HP: [%-*s] 0/0 (0%%)\n", bar_width, "");
        return;
    }

    float ratio = current_health / max_health;
    if (ratio < 0.0f) ratio = 0.0f;
    if (ratio > 1.0f) ratio = 1.0f;

    int filled = (int)ceilf(ratio * (float)bar_width);
    if (filled > bar_width) filled = bar_width;
    if (filled == 0 && current_health > 0.0f) filled = 1;

    const int empty = bar_width - filled;
    const float percent = ratio * 100.0f;

    const char *color =
        (percent >= 70.0f) ? ANSI_COLOR_GREEN  :
        (percent >= 30.0f) ? ANSI_COLOR_YELLOW :
                             ANSI_COLOR_RED;

    printf("HP: [");
    printf("%s", color);
    for (int i = 0; i < filled; ++i) putchar('=');
    printf(ANSI_COLOR_RESET);
    for (int i = 0; i < empty;  ++i) putchar(' ');
    printf("] %.1f/%.1f (%.0f%%)\n", current_health, max_health, percent);
}

static void draw_battle_state(const Character *player,
                              const Character *monster,
                              const int round)
{
    clear_screen();

    printf("%sRound %d%s\n\n", ANSI_COLOR_ORANGE, round, ANSI_COLOR_RESET);

    printf("%s\n", player->name);
    print_health_bar(player->health, player->max_health);
    putchar('\n');

    printf("%s\n", monster->name);
    print_health_bar(monster->health, monster->max_health);
    putchar('\n');

    fflush(stdout);
}

static float calculate_damage(const Character *attacker,
                              const Character *defender,
                              bool *is_critical)
{
    *is_critical = random_int(1, 100) <= 15; /* 15% crit */

    float base = attacker->attack - defender->defense;
    if (base <= 0.0f) base = 1.0f;

    float dmg = random_float(0.85f, 1.15f) * base;
    if (*is_critical) dmg *= 2.0f;

    return dmg;
}

static bool perform_attack(const Character *attacker,
                           Character *defender,
                           float *out_damage,
                           bool  *out_critical)
{
    bool  crit  = false;
    const float dmg   = calculate_damage(attacker, defender, &crit);

    defender->health -= dmg;
    if (defender->health < 0.0f) defender->health = 0.0f;

    *out_damage   = dmg;
    *out_critical = crit;

    return defender->health <= 0.0f;
}

static void print_attack_log(const Character *attacker,
                             const Character *defender,
                             const float damage,
                             const bool  critical)
{
    const bool monster_turn = attacker->class == CLASS_MONSTER;
    const char *color = monster_turn ? ANSI_COLOR_RED : ANSI_COLOR_GREEN;
    const char sign         = monster_turn ? '-' : '+';

    printf("%s attacks %s!\n", attacker->name, defender->name);

    printf("Damage %s: %s%c%.1f%s\n",
           monster_turn ? "taken" : "dealt",
           color, sign, damage, ANSI_COLOR_RESET);
    if (critical)
        printf("%sCritical hit!%s\n", ANSI_COLOR_BRIGHT_YELLOW, ANSI_COLOR_RESET);
}

static void announce_winner(const Character *winner, const Character *player)
{
    println("\nThe battle is over!");
    if (winner == player)
        println("Congratulations! You have defeated the monster!");
    else
        println("You were defeated by the monster...");
}

static void show_battle_intro(const Character *player, const Character *monster)
{
    clear_screen();

    char line[128];
    snprintf(line, sizeof(line),
             "The battle between %s and %s is about to begin...\n\n",
             player->name, monster->name);

    typewriter_print(line);

    printf("%s\n", player->name);
    print_health_bar(player->health, player->max_health);
    putchar('\n');
    printf("%s\n", monster->name);
    print_health_bar(monster->health, monster->max_health);
    fflush(stdout);
}

void start_battle(Character *player, Character *monster)
{
    show_battle_intro(player, monster);
    sleep(3);

    int round = 1;
    const Character *winner = NULL;

    while (is_character_alive(player) && is_character_alive(monster)) {
        float dmg = 0.0f; bool crit = false;
        bool dead = perform_attack(player, monster, &dmg, &crit);

        draw_battle_state(player, monster, round);
        print_attack_log(player, monster, dmg, crit);

        if (dead) { winner = player; break; }
        sleep(2);

        dmg = 0.0f; crit = false;
        dead = perform_attack(monster, player, &dmg, &crit);

        draw_battle_state(player, monster, round);
        print_attack_log(monster, player, dmg, crit);

        if (dead) { winner = monster; break; }
        sleep(2);

        ++round;
    }

    announce_winner(winner, player);
    wait_any_key();
    clear_screen();
}
