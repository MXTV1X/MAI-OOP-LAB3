cmake_minimum_required(VERSION 3.10)
project(MAI-OOP-LAB3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    TLS_VERIFY false
)
FetchContent_MakeAvailable(googletest)

add_library(lab3_lib STATIC
    src/point.cpp
    src/figure.cpp
    src/triangle.cpp
    src/rectangle.cpp
    src/square.cpp
    src/array.cpp
)

add_executable(lab3_exe main.cpp)
target_link_libraries(lab3_exe lab3_lib)

enable_testing()
add_executable(tests test/test.cpp)
target_link_libraries(tests lab3_lib gtest_main)

add_test(NAME Lab3Tests COMMAND tests)
