#include <iostream>
#include "Reaction.cpp"
#include "Agent.cpp"
#include "ReactionCompounds.cpp"
#include "Simulation.cpp"
#include "SymbolTable.hpp"

using namespace SpStochLib;

int main() {
    Simulation example1 = Simulation();
    Simulation example2 = Simulation();
    Simulation example3 = Simulation();

    Agent A = example1.addAgent("A", 100);
    Agent B = example1.addAgent("B", 0);
    Agent C = example1.addAgent("C", 1);

    example1.addReaction(A >>= B, 1);

    example1.simulate(1,std::nullopt);

    return 0;
}