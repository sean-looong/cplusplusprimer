project("expressions")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
include_directories(../getting.started)

add_executable(guess guess.cpp)
add_executable(doWhile doWhile.cpp)
add_executable(ifgrades ifgrades.cpp)
add_executable(vowels vowels.cpp)
add_executable(othercnt othercnt.cpp)
add_executable(rangefor rangefor.cpp)
add_executable(add_item2 add_item2.cpp)
