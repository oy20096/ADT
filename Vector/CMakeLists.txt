cmake_minimum_required(VERSION 3.15)
project(Vector C)

set(CMAKE_C_STANDARD 99)

add_executable(Vector main.c vector.c vector.h SearchAlgo.c SearchAlgo.h sort.c sort.h)