project("copy.control")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
#include_directories(../variables.and.basic.type)

add_executable(copyNoMove copyNoMove.cpp)
add_executable(FolderMain FolderMain.cpp Folder.cpp)
add_executable(HasPtrUseCount HasPtrUseCount.cpp)
add_executable(HasPtrValueLike HasPtrValueLike.cpp)
add_executable(moveHP moveHP.cpp)
