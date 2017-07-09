project("classes")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
#include_directories(../variables.and.basic.type)

add_executable(add_item add_item.cpp Sales_data.cpp Sales_data.h)
