cmake_minimum_required(VERSION 3.19)
add_definitions("-Wall -Wextra -O2 -std=c++17")
project(competitive-library)

add_subdirectory(datastructure)

add_executable(Main main.cpp)
target_link_libraries(
    Main datastructure
)
