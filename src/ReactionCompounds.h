#ifndef SPSTOCHLIB_REACTIONCOMPOUNDS_H
#define SPSTOCHLIB_REACTIONCOMPOUNDS_H

#include <vector>
#include <random>
#include <iostream>
#include "Agent.h"

namespace SpStochLib {

    class ReactionCompounds {
        std::vector<std::reference_wrapper<Agent>> m_agents;
    public:
        [[nodiscard]] std::vector<std::reference_wrapper<Agent>> &agents();

        void addAgent(Agent& agent);

        std::vector<std::reference_wrapper<Agent>>::iterator begin();

        std::vector<std::reference_wrapper<Agent>>::iterator end();

        /** Operator overload for pretty-printing a ReactionCompounds object to an output stream.
         * Fulfills part of requirement 2: "Pretty-print the reaction network in human readable format". */
        friend std::ostream &operator<<(std::ostream &os, const ReactionCompounds &compounds);
    };
    // Agent + Agent
    ReactionCompounds operator+(Agent &agentL, Agent &agentR);

    //ReactionCompound + Agent
    ReactionCompounds operator+(ReactionCompounds &&compound, Agent agent);
} // SpStochLib


#endif //SPSTOCHLIB_REACTIONCOMPOUNDS_H
