cmake_minimum_required(VERSION 3.15)
project(phone_number)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -pedantic-errors -Wall -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wlogical-op -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo")
set(TEST_PATH "C:\\Users\\ENBSF\\DEV\\Courcera\\CpSpec\\TestRunner\\")
add_executable(phone_number main.cpp phone_number.cpp phone_number.h)

include_directories(${TEST_PATH})


