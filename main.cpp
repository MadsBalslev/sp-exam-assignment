#include <iostream>
#include "Reaction.cpp"
#include "Agent.cpp"
#include "ReactionCompounds.cpp"
#include "Simulation.cpp"
#include "SymbolTable.hpp"
#include "examples/Simple.cpp"
#include "examples/Seihr.cpp"
#include "examples/Circadian.cpp"
#include "Plotting/TrajectoryDrawer.cpp"

using namespace SpStochLib;
using namespace SpStochLib::Examples;
using namespace SpStochLib::Plots;


int main() {
    auto example1 = Examples::simple();
    auto example2 = Examples::seihr(10000);
    auto example3 = Examples::circadian();

    TrajectoryDrawer drawer = TrajectoryDrawer();


    example2.simulate(2000, [&drawer](const Simulation &simulation) {
        drawer.addToGraph(simulation);
    });

    return 0;
}