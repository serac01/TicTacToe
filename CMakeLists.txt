cmake_minimum_required(VERSION 3.20)
project(TicTacToe C)

set(CMAKE_C_STANDARD 99)

add_executable(TicTacToe main.c interface.c board.c utils.c structs.h linkedList.c)
