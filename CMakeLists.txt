cmake_minimum_required(VERSION 2.8.4)
project(sudoku_game)

set(CMAKE_CXX_STANDARD 11)

set(LIB_FILES sudoku.cpp sudoku.h)
add_library(sudoku SHARED ${LIB_FILES})

set(EXECUTABLE_FILES main.cpp)
add_executable(tester ${EXECUTABLE_FILES})
target_link_libraries(tester sudoku)
