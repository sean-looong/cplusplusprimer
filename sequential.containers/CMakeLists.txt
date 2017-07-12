cmake_minimum_required(VERSION 3.5)
project("sequential.containers")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(capacity capacity.cpp)
