#ifndef SPSTOCHLIB_PARALLELRUNNER_H
#define SPSTOCHLIB_PARALLELRUNNER_H

#include "Simulation.h"

// 8. Implement support for multiple computer cores by parallelizing the computation of several simulations at the same time.
// Estimate the likely (average) value of the hospitalized peak over 100 simulations.

namespace SpStochLib {

    class ParallelRunner {
        std::vector<Simulation> m_simulations;
        std::optional<std::function<void(size_t, const Simulation&)>> m_callback;

    public:
        void run(size_t count, double endTime, const std::function<Simulation()> &simulationFactory, size_t numThreads);
        void setCallback(const std::function<void(size_t, const Simulation&)> &callback);
    };

} // SpStochLib

#endif //SPSTOCHLIB_PARALLELRUNNER_H
