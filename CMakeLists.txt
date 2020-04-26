cmake_minimum_required(VERSION 3.16)
project(test C)

set(CMAKE_C_STANDARD 11)

add_executable(test main.c src/PokerHand.c src/Combinations/isFlush.c inc/methods.h
        src/utils/ErrorHandler.c inc/minilib.h src/utils/lib.c
        src/utils/mx_del_extra_whitespaces.c src/utils/mx_strtrim.c
        src/utils/getPokerHand.c src/utils/sort_poker_hand.c src/utils/print_result.c src/Combinations/isStraight.c src/utils/PokerHandErraser.c src/utils/GenerateCard.c src/Combinations/is4s.c src/Combinations/isFullHouse.c src/Combinations/is3s.c src/Combinations/is22s.c src/Combinations/is2s.c)
include_directories(inc)