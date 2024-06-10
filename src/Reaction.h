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

        void addReactant(const Agent& reactant);
        void addProduct (const Agent& product);

        void computeDelay(std::mt19937 &generator);

        // Overload output stream to pretty print
        friend std::ostream &operator<<(std::ostream &os, Reaction &reaction);
    };


    // A + B -> C
    Reaction operator>>=(ReactionCompounds &&compounds, const Agent &agent);
    // A -> B + C
    Reaction operator>>=(const Agent &agent, ReactionCompounds &&compounds);
    // A + B -> C + D
    Reaction operator>>= (const ReactionCompounds &compoundsL, const ReactionCompounds &compoundsR);
    // A -> B
    Reaction operator>>=(const Agent &agentL, const Agent &agentR);

}

#endif //SPSTOCHLIB_REACTION_H
