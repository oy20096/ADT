cmake_minimum_required(VERSION 3.15)
project(LIST C)

set(CMAKE_C_STANDARD 99)

add_executable(LIST main.c List.c List.h sort.h sort.c)