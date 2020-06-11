cmake_minimum_required(VERSION 3.16)
project(Jumping_Elephant)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/vs2019)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/mingw64)
endif()

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src DIR_SRCS)
add_executable(Jumping_Elephant ${DIR_SRCS})
target_link_libraries(Jumping_Elephant -lgraphics64 -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32 -lwinmm -lgdiplus)