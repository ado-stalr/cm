cmake_minimum_required(VERSION 3.21)
project(lw1_2)

set(BOOST_ROOT "C:/boost_1_79_0")
set(BOOSTROOT "C:/boost_1_79_0")
find_package(Boost 1.79.0)
set(Boost_INCLUDE_DIR C:/boost_1_79_0/)
set(Boost_LIBRARY_DIR C:/boost_1_79_0/stage/lib)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(lw1_2 main.cpp)
