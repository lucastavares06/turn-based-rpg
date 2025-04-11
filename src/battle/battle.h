#ifndef BATTLE_H
#define BATTLE_H

#include <stdbool.h>
#include <character.h>

bool is_character_alive(const Character *character);

void start_battle(Character *player, Character *monster);

#endif
