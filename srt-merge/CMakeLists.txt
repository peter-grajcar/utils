cmake_minimum_required(VERSION 3.10)

add_executable(srt-merge src/srt_merge.c)

target_include_directories(srt-merge PUBLIC include)

