#ifndef SPSTOCHLIB_REACTIONCOMPOUNDS_H
#define SPSTOCHLIB_REACTIONCOMPOUNDS_H

#include <vector>
#include "Agent.h"

namespace SpStochLib {

    class ReactionCompounds {
        std::vector<Agent> m_agents;
    public:
        const std::vector<Agent> &agents() const;

        void addAgent(const Agent& agent);

        [[nodiscard]] const std::vector<Agent>::const_iterator begin() const;
        [[nodiscard]] const std::vector<Agent>::const_iterator end() const;

        std::vector<Agent>::iterator begin();
        std::vector<Agent>::iterator end();
    };
} // SpStochLib


#endif //SPSTOCHLIB_REACTIONCOMPOUNDS_H
