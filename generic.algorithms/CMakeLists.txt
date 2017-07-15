cmake_minimum_required(VERSION 3.5)
project("generic.algorithms")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(absInt absInt.cpp)
add_executable(accum accum.cpp)
add_executable(accum4 accum4.cpp)
add_executable(bind2 bind2.cpp)
add_executable(elimDups elimDups.cpp)
add_executable(equal equal.cpp)
add_executable(equiv-istream-iter equiv-istream-iter.cpp)
add_executable(inserters inserters.cpp)
add_executable(iostream_iter iostream_iter.cpp)
