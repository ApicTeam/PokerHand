cmake_minimum_required(VERSION 3.16)
project(test C)

set(CMAKE_C_STANDARD 11)

add_executable(test main.c src/PokerHand.c src/isFlush.c inc/methods.h
        src/ErrorHandler.c inc/minilib.h src/lib.c
        src/mx_del_extra_whitespaces.c src/mx_strtrim.c
        src/getPokerHand.c src/sort_poker_hand.c src/print_result.c)
include_directories(inc)