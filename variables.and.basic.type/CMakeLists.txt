project("getting started")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

add_executable(convs convs.cpp)
add_executable(escape escape.cpp)
add_executable(inits inits.cpp)
add_executable(literals literals.cpp)
add_executable(ref-ex ref-ex.cpp)
add_executable(unsigned unsigned.cpp)
add_executable(scope_levels scope_levels.cpp)
add_executable(decl-ex decl-ex.cpp)
