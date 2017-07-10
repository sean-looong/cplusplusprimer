cmake_minimum_required(VERSION 3.5)
project("classes")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
include_directories(../classes)

add_executable(add_item add_item.cpp ../classes/Sales_data.cpp ../classes/Sales_data.h)
add_executable(add_itemV2 add_itemV2.cpp ../classes/Sales_data.cpp ../classes/Sales_data.h)
add_executable(buf buf.cpp)
add_executable(clearIO clearIO.cpp)
add_executable(fileIO fileIO.cpp)
add_executable(sstream sstream.cpp)
