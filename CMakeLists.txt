cmake_minimum_required(VERSION 3.5)

project(statistics VERSION ${PROJECT_VERSION})


set(SOURCES
      statistic.cpp
)
set(HEADERS
        poly_calc.h calculates.h
)

add_executable(statistics ${SOURCES} ${HEADERS})
set_target_properties(
        statistics PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)
