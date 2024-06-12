#include "Simulation.h"
#include "ParallelRunner.h"
#include "vector"
#include "Examples/Seihr.cpp"

// 8. Implement support for multiple computer cores by parallelizing the computation of several simulations at the same time.
// Estimate the likely (average) value of the hospitalized peak over 100 simulations.

namespace SpStochLib::Estimation {
    std::pair<double, double> estimatePeakMean(size_t N, size_t endTime, size_t simulationCount = 100) {
        std::vector<double> maxValues(simulationCount, 0);
        std::mutex mtx;

        ParallelRunner runner;

        runner.setCallback([&](size_t index, const Simulation &simulation) {
            auto& hospitalized = simulation.agents()["H"];
            double quantity = hospitalized.amount();

            std::lock_guard<std::mutex> guard(mtx);
            if (quantity > maxValues[index]) {
                maxValues[index] = quantity;
            }
        });

        runner.run(simulationCount, endTime, [N]() { return Examples::seihr(N); }, 0);


        double peak = 0.0;
        double mean = 0.0;

        for (double value: maxValues) {
            mean += value;
            if (value > peak) {
                peak = value;
            }
        }

        mean /= static_cast<double>(simulationCount);

        return {peak, mean};
    };
}