cmake_minimum_required(VERSION 3.27)
project(SpStochLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)

include(doctest.cmake)
include(benchmark.cmake)

enable_testing()
include_directories(src)

# Graphviz paths
set(GRAPHVIZ_INCLUDE_DIR "C:/Program Files/Graphviz/include")
set(GRAPHVIZ_LIBRARY_DIR "C:/Program Files/Graphviz/lib")

# Add Graphviz directories
include_directories(${GRAPHVIZ_INCLUDE_DIR})
link_directories(${GRAPHVIZ_LIBRARY_DIR})

add_subdirectory(src)

add_executable(SpStochLibMain main.cpp)

target_link_libraries(SpStochLibMain PRIVATE SpStochLib cgraph gvc)
target_link_libraries(SpStochLibMain PUBLIC sciplot)
include_directories("${GRAPHVIZ_DIR}/include/graphviz")

add_subdirectory(tests)
add_subdirectory(estimation)
add_subdirectory(benchmarking)
