cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 23)

# source files without the 'src/' prefix
set(SOURCE_FILES
        Agent.cpp
        ReactionCompounds.cpp
        Reaction.cpp
        Simulation.cpp
        SymbolTable.cpp
        SymbolTable.h)


add_library(SpStochLib ${SOURCE_FILES})
