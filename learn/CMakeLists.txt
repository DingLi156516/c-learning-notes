cmake_minimum_required(VERSION 3.15)
project(learn C)

set(CMAKE_C_STANDARD 99)

add_executable(learn main.c increment.c negate.c data_structure/stack.c data_structure/stack.h)