cmake_minimum_required(VERSION 3.5)

project(01.test_project)

add_executable(test_project 
    hello_world.cpp
    example.cpp
    move_me_out.cpp
    move_me_out.h
    example.h
)

set_target_properties(test_project PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


install(TARGETS test_project )