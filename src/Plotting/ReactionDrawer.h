#ifndef SPSTOCHLIB_REACTIONDRAWER_H
#define SPSTOCHLIB_REACTIONDRAWER_H

#include "Simulation.h"
#include "graphviz/gvc.h"

namespace SpStochLib::Plots {
    class ReactionDrawer {
        static void createNode(Agraph_t *graph, const std::string &name, const std::string &fillColor,
                               const std::string &shape = "circle");
        static void createEdge(Agraph_t *agraph, const std::string &source, const std::string &destination);
        static std::string round(double &num);

    public:
        static void draw(SpStochLib::Simulation &simulation, const std::string &fileName);
    };

}
#endif //SPSTOCHLIB_REACTIONDRAWER_H
