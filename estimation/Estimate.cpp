#include "Simulation.h"
#include "ParallelRunner.h"
#include "vector"
#include "Examples/Seihr.cpp"

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

            std::cout << "Simulation " << index << " has peak value " << quantity << std::endl;
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