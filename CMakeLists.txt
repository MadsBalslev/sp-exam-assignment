cmake_minimum_required(VERSION 3.27)
project(SpStochLib)

set(CMAKE_CXX_STANDARD 23)

include_directories(src)

add_subdirectory(src)

add_executable(SpStochLibMain main.cpp)
