cmake_minimum_required(VERSION 3.5)
project("associative.containers")

#include_directories(../functions)
#include_directories(../getting.started)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(erasemap erasemap.cpp)
