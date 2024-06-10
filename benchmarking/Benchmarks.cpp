#include "ParallelRunner.h"
#include "chrono"
#include <benchmark/benchmark.h>
#include "Simulation.h"
#include "Examples/Simple.cpp"
#include "Examples/Seihr.cpp"
#include <thread>

// Benchmark and compare the stochastic simulation performance (e.g. the time it takes to compute 100 simulations
// a single core, multiple cores, or improved implementation). Record the timings and make your conclusions.

constexpr size_t simulationCount = 8;
constexpr size_t numIterations = 100;
constexpr size_t endTime = 100;

SpStochLib::Simulation createSimulation() {
    return SpStochLib::Examples::seihr(10000);
}


void BM_SimulationSynchronous(benchmark::State& state) {
    int numSimulations = state.range(0);

    std::vector<SpStochLib::Simulation> simulations(numSimulations);

    for (auto _ : state) {
        for (auto& simulation : simulations) {
            simulation = createSimulation();
            simulation.simulate(endTime, std::nullopt);
        }
    }
}

BENCHMARK(BM_SimulationSynchronous)->Iterations(numIterations)->RangeMultiplier(2)->Range(1, simulationCount)  ->Unit(benchmark::kMillisecond);

void BM_SimulationParallel(benchmark::State& state) {
    SpStochLib::ParallelRunner runner;
    size_t numSimulations = state.range(0);
    size_t numThreads = state.range(1);

    for (auto _ : state) {
        runner.run(numSimulations, endTime, createSimulation, numThreads);
    }
}

static void customThreadAndSimulationCountArguments(benchmark::internal::Benchmark* b) {
    std::vector<int> threadCounts;

    for (int i = 2; i <= std::thread::hardware_concurrency(); i *= 2) {
        threadCounts.push_back(i);
    }

    // Add the case with 0 threads for the simulation runner (becomes OS choice)
    for (int simulations = 1; simulations <= simulationCount; simulations *= 2) {
        b->Args({simulations, 0});
    }

    for (const auto& threads : threadCounts) {
        for (int simulations = 1; simulations <= simulationCount; simulations *= 2) {
            b->Args({simulations, threads});
        }
    }
}

BENCHMARK(BM_SimulationParallel)->Iterations(numIterations)->Apply(customThreadAndSimulationCountArguments)->Unit(benchmark::kMillisecond);

int main(int argc, char** argv) {
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}
