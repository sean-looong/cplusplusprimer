cmake_minimum_required(VERSION 3.5)
project("overloaded.operations.and.conversions")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
include_directories(../functions)
include_directories(../getting.started)

add_executable(absInt absInt.cpp)
add_executable(add add.cpp Sales_data.cpp)
add_executable(calc calc.cpp)
add_executable(directcall directcall.cpp Sales_data.cpp)
add_executable(fcnobj fcnobj.cpp)
add_executable(newcount-size newcount-size.cpp)
add_executable(readStr readStr.cpp)
