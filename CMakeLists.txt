cmake_minimum_required(VERSION 3.10)
project(sat-solver C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(sat-solver src/main.c src/solver.c)
