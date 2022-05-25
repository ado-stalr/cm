cmake_minimum_required(VERSION 3.21)
project(lw4_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")


add_executable(lw4_2 main.cpp)
