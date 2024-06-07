#include <iostream>
#include "Reaction.cpp"
#include "Agent.cpp"
#include "ReactionCompounds.cpp"
#include "Simulation.cpp"
#include "SymbolTable.hpp"
#include "examples/Simple.cpp"

using namespace SpStochLib;
using namespace SpStochLib::Examples;


int main() {
    Simulation example1 = simple();

    example1.simulate(2000, std::nullopt);

    return 0;
}