cmake_minimum_required (VERSION 2.6)

project (Menger)

set (SRC ${PROJECT_SOURCE_DIR}/src)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++11 -O2 -g -I${SRC}")

add_subdirectory (tst)
add_subdirectory (src_main)
