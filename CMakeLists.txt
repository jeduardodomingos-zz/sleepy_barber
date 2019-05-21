cmake_minimum_required(VERSION 3.14)
project(sleepy_barber C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(sleepy_barber main.c)