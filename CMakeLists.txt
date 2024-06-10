cmake_minimum_required(VERSION 3.27)
project(SpStochLib)

set(CMAKE_CXX_STANDARD 23)

include(doctest.cmake)

enable_testing()

include_directories(src)

add_subdirectory(src)

add_executable(SpStochLibMain main.cpp)

target_link_libraries(SpStochLibMain PRIVATE SpStochLib)
target_link_libraries(SpStochLibMain PUBLIC sciplot)

add_subdirectory(tests)
add_subdirectory(estimation)
