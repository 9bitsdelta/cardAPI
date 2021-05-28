cmake_minimum_required(VERSION 3.17)
project(Homework C)

set(CMAKE_C_STANDARD 99)

add_executable(run-war src/run-war.c src/datastruct.c src/game.c src/cards.c)
add_executable(run-septica src/run-septica.c src/datastruct.c src/game.c src/cards.c)
