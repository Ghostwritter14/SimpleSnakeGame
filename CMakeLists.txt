cmake_minimum_required(VERSION 3.28)
project(cmdlineSnakeGame)

set(CMAKE_CXX_STANDARD 23)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(cmdlineSnakeGame main.cpp)