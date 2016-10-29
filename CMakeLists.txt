cmake_minimum_required(VERSION 3.5)
project(SeqFit)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES main.c myMalloc.c myMalloc.h)
add_executable(SeqFit ${SOURCE_FILES})