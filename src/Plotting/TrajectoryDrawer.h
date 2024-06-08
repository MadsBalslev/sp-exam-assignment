#ifndef SPSTOCHLIB_TRAJECTORYDRAWER_H
#define SPSTOCHLIB_TRAJECTORYDRAWER_H

#include "Simulation.h"
#include "vector"

namespace SpStochLib::Plots {
    class TrajectoryDrawer {


    public:
        void draw();
        void addToGraph(const Simulation &sim);
    };
}


#endif //SPSTOCHLIB_TRAJECTORYDRAWER_H
