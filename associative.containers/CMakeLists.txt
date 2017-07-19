cmake_minimum_required(VERSION 3.5)
project("associative.containers")

#include_directories(../functions)
#include_directories(../getting.started)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(erasemap erasemap.cpp)
add_executable(map1 map1.cpp)
add_executable(multimap multimap.cpp)
add_executable(pair pair.cpp)
add_executable(restricted_count restricted_count.cpp)
add_executable(setOps setOps.cpp)
add_executable(unorderedWordCount unorderedWordCount.cpp)
add_executable(wcEx wcEx.cpp)
add_executable(word_count word_count.cpp)
add_executable(word_transform word_transform.cpp)
