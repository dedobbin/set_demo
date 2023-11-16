cmake_minimum_required(VERSION 3.10)

project(handrolled)

include_directories(
    inc
)

set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/strategy/simple_strategy.cpp
    src/set.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "set_assignment")