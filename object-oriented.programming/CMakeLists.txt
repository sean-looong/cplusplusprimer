project("classes")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
#include_directories(../variables.and.basic.type)

add_executable(useQuote useQuote.cpp Quote.cpp)
