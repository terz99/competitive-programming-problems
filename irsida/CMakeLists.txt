cmake_minimum_required(VERSION 3.8)
project(irsida)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Program.cpp Program.h)
add_executable(irsida ${SOURCE_FILES})