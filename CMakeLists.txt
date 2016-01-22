cmake_minimum_required (VERSION 2.6)

project (Menger)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic -std=c++11 -O2 -g -I${PROJECT_SOURCE_DIR}")

add_subdirectory (tst)
