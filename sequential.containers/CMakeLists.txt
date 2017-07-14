cmake_minimum_required(VERSION 3.5)
project("sequential.containers")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(capacity capacity.cpp)
add_executable(erase1 erase1.cpp)
add_executable(erase2 erase2.cpp)
add_executable(find_ops find_ops.cpp)
add_executable(find-str find-str.cpp)
add_executable(refreshIter refreshIter.cpp)
add_executable(stack stack.cpp)
add_executable(str_assignOps str_assignOps.cpp)
add_executable(substring substring.cpp)
