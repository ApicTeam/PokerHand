cmake_minimum_required(VERSION 3.16)
project(test C)

set(CMAKE_C_STANDARD 11)

add_executable(test main.c src/PokerHand.c src/isFlush.c inc/methods.h src/getPokerHand.c src/ErrorHandler.c inc/minilib.h src/lib.c)
include_directories(inc)