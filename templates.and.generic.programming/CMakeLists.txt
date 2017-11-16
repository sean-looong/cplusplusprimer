cmake_minimum_required(VERSION 3.5)
project("templates.and.generic.programming")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -DDEBUG")

add_executable(compare compare.cpp)
add_executable(compareSpec compareSpec.cpp)
add_executable(useBlob useBlob.cpp)
add_executable(useChecking useChecking.cpp)
add_executable(Array Array.cpp)
add_executable(array-parms4 array-parms4.cpp)
add_executable(compareDef compareDef.cpp Sales_data.cpp)
add_executable(debug debug.cpp)
