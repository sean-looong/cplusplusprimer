cmake_minimum_required(VERSION 3.5)
project("dynamic.memory")

#include_directories(../functions)
#include_directories(../getting.started)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(allocPtr allocPtr.cpp)
add_executable(allocSP allocSP.cpp)
add_executable(oknew oknew.cpp)
add_executable(usealloc usealloc.cpp)
add_executable(usealloc2 usealloc2.cpp)
add_executable(release release.cpp)
add_executable(unique unique.cpp)
add_executable(up up.cpp)
add_executable(useBlob useBlob.cpp)
add_executable(weak weak.cpp)
