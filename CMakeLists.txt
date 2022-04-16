cmake_minimum_required(VERSION 3.5)

project(01.game)

add_executable(game 
        game.cpp
)

set_target_properties(game PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)