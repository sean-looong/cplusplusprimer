project("classes")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
#include_directories(../variables.and.basic.type)

add_executable(add_item add_item.cpp Sales_data.cpp Sales_data.h)
add_executable(avg_price avg_price.cpp Sales_data.cpp Sales_data.h)
add_executable(useAccount useAccount.cpp Account.cpp Account.h)
add_executable(useDebug useDebug.cpp Debug.cpp Debug.h)
add_executable(useScreen useScreen.cpp Screen.h)
