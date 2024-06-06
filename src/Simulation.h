#ifndef SPSTOCHLIB_SIMULATION_H
#define SPSTOCHLIB_SIMULATION_H

#include <Reaction.h>
#include <algorithm>


namespace SpStochLib {

    class Simulation {
        double m_time = 0;

        bool canReact(Reaction& reaction);
        void react(Reaction& reaction);
        Reaction& getMinDelayReaction();
    public:
        [[nodiscard]] double time() const;

        void simulate(double endTime);
    };
}

#endif //SPSTOCHLIB_SIMULATION_H
