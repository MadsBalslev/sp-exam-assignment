#ifndef SPSTOCHLIB_SIMPLE_CPP
#define SPSTOCHLIB_SIMPLE_CPP

#include "Simulation.h"
#include "Reaction.h"


namespace SpStochLib::Examples {
    Simulation simple(size_t a = 100, size_t b = 0, size_t c = 1) {
        const double lambda = 0.001;

        Simulation simulation{};

        auto& agentA = simulation.addAgent("A", a);
        auto& agentB = simulation.addAgent("B", b);
        auto& agentC = simulation.addAgent("C", c);

        ReactionCompounds compoundL = agentA + agentB;
        ReactionCompounds compoundR = agentB + agentC;

        simulation.addReaction(compoundL >>= compoundR, lambda);

        return simulation;
    }
}

#endif