cmake_minimum_required(VERSION 3.23)
project(OS_LAB4)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-shared -fpic)

add_executable(OS_LAB4 main.cpp)
