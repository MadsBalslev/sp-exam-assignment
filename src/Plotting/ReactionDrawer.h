#ifndef SPSTOCHLIB_REACTIONDRAWER_H
#define SPSTOCHLIB_REACTIONDRAWER_H

#include "Simulation.h"

namespace SpStochLib::Plots {
    class ReactionDrawer {
        void createNode();

        void createEdge();

    public:
        void draw(SpStochLib::Simulation &simulation, const std::string &fileName);
    };

}
#endif //SPSTOCHLIB_REACTIONDRAWER_H
