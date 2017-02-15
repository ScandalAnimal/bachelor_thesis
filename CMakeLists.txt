cmake_minimum_required(VERSION 3.5)
project(bachelor_thesis)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        code/evaluator.c
        code/evaluator.h
        code/hashmap.c
        code/hashmap.h
        code/main.c)

add_executable(bachelor_thesis ${SOURCE_FILES})