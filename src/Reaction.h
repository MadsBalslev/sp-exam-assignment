#ifndef SPSTOCHLIB_REACTION_H
#define SPSTOCHLIB_REACTION_H

#include <random>
#include <sstream>
#include <string>
#include "ReactionCompounds.h"

namespace SpStochLib {
    class Reaction {
        ReactionCompounds m_reactants;
        ReactionCompounds m_products;

    public:
        double rate = 0;
        double delay = 0;

        [[nodiscard]] std::string name() const;

        [[nodiscard]]ReactionCompounds &reactants();
        [[nodiscard]]ReactionCompounds &products();

        void addReactant(Agent& reactant);
        void addProduct (Agent& product);

        void computeDelay(std::mt19937 &generator);

        // Overload output stream to pretty print
        friend std::ostream &operator<<(std::ostream &os, Reaction &reaction);
    };

    // 1. The library should overload operators to support the reaction rule typesetting directly in C++ code.
    // A + B -> C
    Reaction operator>>=(ReactionCompounds &&compounds, Agent &agent);
    // A -> B + C
    Reaction operator>>=(Agent &agent, ReactionCompounds &&compounds);
    // A + B -> C + D
    Reaction operator>>= (ReactionCompounds &compoundsL, ReactionCompounds &compoundsR);
    // A -> B
    Reaction operator>>=(Agent &agentL, Agent &agentR);

}

#endif //SPSTOCHLIB_REACTION_H
