cmake_minimum_required(VERSION 3.8)
project(todo_sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Date.cpp Date.h)
add_executable(todo_sort ${SOURCE_FILES})