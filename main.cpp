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
    Simulation example2 = simple(100,0,2);
    Simulation example3 = simple(50,50,1);

    example1.simulate(2000, std::nullopt);
    example2.simulate(2000, std::nullopt);
    example3.simulate(2000, std::nullopt);

    return 0;
}