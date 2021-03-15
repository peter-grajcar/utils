cmake_minimum_required(VERSION 3.10)

add_executable(chardiff src/chardiff.c)

target_include_directories(chardiff PUBLIC include)

