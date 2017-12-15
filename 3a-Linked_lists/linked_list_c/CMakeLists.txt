cmake_minimum_required(VERSION 3.0)

project(linked_list)
set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SOURCE_FILES
    linked_list.c
    unittest.h)
add_executable(linked_list ${SOURCE_FILES})
