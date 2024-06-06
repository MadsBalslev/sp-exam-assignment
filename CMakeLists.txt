cmake_minimum_required(VERSION 3.27)
project(Sp_Exam_Try_2)

set(CMAKE_CXX_STANDARD 23)

include_directories(src)

add_subdirectory(src)

add_executable(Sp_Exam_Try_2Main main.cpp)
