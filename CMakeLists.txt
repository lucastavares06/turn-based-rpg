cmake_minimum_required(VERSION 3.30)
project(turn_based_rpg C)

set(CMAKE_C_STANDARD 17)

add_executable(turn_based_rpg
        src/main.c
        src/utils/utils.c
        src/character/character.c
        src/menu/menu.c
        src/game/game.c
)
