cmake_minimum_required(VERSION 3.13)
project(DistributedandParallelSystemsDTU C)

set(CMAKE_C_STANDARD 99)

add_executable(DistributedandParallelSystemsDTU main.c)


add_executable(memory "Lecture 1/memory.c")
add_executable(pointers "Lecture 1/pointers.c")
add_executable(timing "Lecture 1/timing.c")