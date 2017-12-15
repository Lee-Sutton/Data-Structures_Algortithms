cmake_minimum_required(VERSION 3.8)
project(C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        main.c
        stack.h
        cunit.h
        cunit.c)
add_executable(C ${SOURCE_FILES})