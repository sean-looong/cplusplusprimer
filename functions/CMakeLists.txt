project("expressions")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
#include_directories(../getting.started)

add_executable(fact fact.cpp LocalMath.cpp LocalMath.h)
add_executable(reset reset.cpp)
add_executable(count-calls count-calls.cpp)
add_executable(errMsg_initList errMsg_initList.cpp)
add_executable(good_printmain good_printmain.cpp)
add_executable(inline_shorter inline_shorter.cpp)
add_executable(arrRet arrRet.cpp)
add_executable(fcnptrRet fcnptrRet.cpp)
