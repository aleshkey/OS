cmake_minimum_required(VERSION 3.24)
project(lab4_3_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4_3_0 main.cpp alloc.c)

enable_testing()
add_subdirectory(googletest)
add_executable(test_app tests.cpp alloc.c)
target_link_libraries(test_app gtest_main)