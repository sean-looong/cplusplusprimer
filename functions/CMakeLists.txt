project("expressions")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
#include_directories(../getting.started)

add_executable(fact fact.cpp LocalMath.cpp LocalMath.h)
