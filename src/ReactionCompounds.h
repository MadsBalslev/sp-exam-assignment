#ifndef SPSTOCHLIB_REACTIONCOMPOUNDS_H
#define SPSTOCHLIB_REACTIONCOMPOUNDS_H

#include <vector>
#include <random>
#include <iostream>
#include "Agent.h"

namespace SpStochLib {

    class ReactionCompounds {
        std::vector<Agent> m_agents;
    public:
        [[nodiscard]] const std::vector<Agent> &agents() const;

        void addAgent(const Agent& agent);

        [[nodiscard]] std::vector<Agent>::const_iterator begin() const;
        [[nodiscard]] std::vector<Agent>::const_iterator end() const;

        std::vector<Agent>::iterator begin();
        std::vector<Agent>::iterator end();

        /** Operator overload for pretty-printing a ReactionCompounds object to an output stream.
         * Fulfills part of requirement 2: "Pretty-print the reaction network in human readable format". */
        friend std::ostream &operator<<(std::ostream &os, const ReactionCompounds &compounds);
    };
} // SpStochLib


#endif //SPSTOCHLIB_REACTIONCOMPOUNDS_H
