cmake_minimum_required(VERSION 3.14)
project(Work_algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(range-minimum-query)

add_executable(Work_algorithms
        range-minimum-query/index.cpp
        range-minimum-query/index.h
        main.cpp)
