cmake_minimum_required(VERSION 3.5)
project("generic.algorithms")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(absInt absInt.cpp)
add_executable(accum accum.cpp)
add_executable(accum4 accum4.cpp)
