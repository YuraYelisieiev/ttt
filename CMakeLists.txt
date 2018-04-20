cmake_minimum_required(VERSION 3.8)
project(oop_ttt)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(oop_ttt main.cpp game_board.cpp game_board.h)