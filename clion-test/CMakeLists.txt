cmake_minimum_required(VERSION 3.8)
project(clion_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Date.cpp Date.h)
add_executable(clion_test ${SOURCE_FILES})