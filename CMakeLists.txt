cmake_minimum_required(VERSION 3.19)

add_definitions("-Wall -O2 -std=c++17")

project(competitive-library)

add_subdirectory(algorithm)
add_executable(Main main.cpp)

target_link_libraries(Main INTERFACE algorithm)
target_include_directories(Main INTERFACE
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/algorithm"
)