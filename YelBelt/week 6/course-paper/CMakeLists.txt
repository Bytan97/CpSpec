cmake_minimum_required(VERSION 3.16)
project(course_paper)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors -Wall -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wlogical-op -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo")
set(TEST_PATH "C:\\Users\\ENBSF\\DEV\\Courcera\\CpSpec\\TestRunner\\")
add_executable(course_paper main.cpp database.cpp database.h date.cpp date.h token.cpp token.h node.cpp node.h condition_parser.cpp condition_parser_test.cpp condition_parser.h)

include_directories(${TEST_PATH})