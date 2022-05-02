cmake_minimum_required(VERSION 3.5)

project(game)

set(SOURCES
game.cpp random_game.cpp file.cpp
)

set(HEADERS
 random_game.h file.h
)

add_executable(game ${SOURCES} ${HEADERS})

set_target_properties(
        game PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)