project("getting started")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(add add.cpp)
add_executable(whilecount whilecount.cpp)
add_executable(forcount forcount.cpp)
add_executable(mysum mysum.cpp)
add_executable(occurs occurs.cpp)
add_executable(item_io item_io.cpp Sales_item.h)
add_executable(add_item add_item.cpp Sales_item.h)
add_executable(add_item2 add_item2.cpp Sales_item.h)
add_executable(avg_price avg_price.cpp Sales_item.h)
