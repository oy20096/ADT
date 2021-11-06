cmake_minimum_required(VERSION 3.15)
project(BinTree C)

set(CMAKE_C_STANDARD 99)

add_executable(BinTree main.c bintree.c bintree.h binstack.c)