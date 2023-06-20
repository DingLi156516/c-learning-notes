cmake_minimum_required(VERSION 3.15)
project(learn C)

set(CMAKE_C_STANDARD 99)

add_executable(learn main.c negate.c data_structure/stack.c data_structure/stack.h data_structure/string.h data_structure/string.c data_structure/queue.h data_structure/queue.c data_structure/hashset.c data_structure/hashset.h)