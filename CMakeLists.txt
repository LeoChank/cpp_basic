cmake_minimum_required(VERSION 3.5)

project(calc VERSION ${PROJECT_VERSION})


set(SOURCES
        calc.cpp
        astnode.cpp
        lexer.cpp 
        parser.cpp

)
set(HEADERS
        astnode.hpp
        lexer.hpp
        number.hpp
        parser.hpp
)

add_executable(calc ${SOURCES} ${HEADERS})
set_target_properties(
        calc PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
