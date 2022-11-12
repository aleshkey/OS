cmake_minimum_required(VERSION 3.23)
project(OS_lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(OS_lab3 main.cpp)

set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

SET(CMAKE_CXX_FLAGS -pthread)