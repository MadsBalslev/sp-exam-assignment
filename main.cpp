#include <iostream>
#include "Reaction.cpp"
#include "Agent.cpp"
#include "ReactionCompounds.cpp"
#include "SymbolTable.hpp"

using namespace SpStochLib;

int main() {
    Agent agentA = Agent{"A", 5};
    Agent agentB = Agent{"B", 5};
    Agent agentC = Agent{"C", 5};
    auto rate = 5;

    Reaction reaction = agentA + agentC >>= agentB;
    std::cout << reaction.name();
    SymbolTable symbolTable = SymbolTable<std::string, std::string>();
    


    return 0;
}
