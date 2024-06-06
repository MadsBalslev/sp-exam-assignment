#ifndef SPSTOCHLIB_REACTION_H
#define SPSTOCHLIB_REACTION_H

#include <random>
#include "ReactionCompounds.h"

namespace SpStochLib {
    class Reaction {
        ReactionCompounds m_reactants;
        ReactionCompounds m_products;

    public:
        double rate = 0;
        double delay = 0;



        [[nodiscard]]ReactionCompounds &reactants();
        [[nodiscard]] ReactionCompounds &products();

        void addReactant(Agent &reactant);
        void addProduct (Agent &product);

        void computeDelay(std::mt19937 &generator);

        // Overload output stream to pretty print
        friend std::ostream &operator<<(std::ostream &os, Reaction &reaction);
    };


    // A + B -> C
    Reaction operator>>=(ReactionCompounds &&compounds, Agent &agent);
    // A -> B
    Reaction operator>>=(Agent &agentL,Agent &agentR);
    // A -> B + C
    Reaction operator>>=(Agent &agent, ReactionCompounds &&compounds);
    // A + B -> C + D
    Reaction operator>>= (ReactionCompounds &compoundsL, ReactionCompounds &compoundsR);

}

#endif //SPSTOCHLIB_REACTION_H
