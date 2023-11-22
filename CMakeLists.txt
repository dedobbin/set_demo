cmake_minimum_required(VERSION 3.10)

project(handrolled)

include_directories(
    inc
)

set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/set.cpp
    
    src/strategy/simple_strategy.cpp 
    src/strategy/binary_search.cpp
    src/strategy/handrolled_binary_search.cpp

    src/tests/strategy_test.cpp

    src/benchmarks/strategy_benchmark.cpp
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Debug build")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3")
elseif(CMAKE_BUILD_TYPE MATCHES Release)    
    message(STATUS "Release build")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -flto")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "set_assignment")