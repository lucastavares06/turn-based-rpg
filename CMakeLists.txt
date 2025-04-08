cmake_minimum_required(VERSION 3.30)
project(turn_based_rpg C)

set(CMAKE_C_STANDARD 17)

add_executable(turn_based_rpg
        main.c
        utils/utils.c
)
