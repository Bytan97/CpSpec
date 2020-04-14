cmake_minimum_required(VERSION 3.15)
project(sum_reverse_sort)

set(CMAKE_CXX_STANDARD 17)
set(TEST_PATH "C:\\Users\\ENBSF\\DEV\\Courcera\\CpSpec\\TestRunner\\")
add_executable(sum_reverse_sort  main.cpp sum_reverse_sort.cpp)

include_directories(${TEST_PATH})