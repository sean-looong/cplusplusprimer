cmake_minimum_required(VERSION 3.5)
project("overloaded.operations.and.conversions")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
include_directories(../getting.started)

add_executable(absInt absInt.cpp)
add_executable(add add.cpp Sales_data.cpp)
