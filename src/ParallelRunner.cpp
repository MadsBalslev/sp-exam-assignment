#include "ParallelRunner.h"
#include "ThreadPool.hpp"

namespace SpStochLib {
    void ParallelRunner::run(size_t count,
                             double endTime,
                             const std::function<Simulation()> &simulationFactory,
                             size_t num_Threads) {

        m_simulations.resize(count);

        auto runSimulation = [this, endTime, &simulationFactory](size_t index) {
            m_simulations[index] = simulationFactory();

            if (m_callback) {
                m_simulations[index].simulate(endTime, [this, index](const Simulation &simulation) {
                    (*m_callback)(index, simulation);
                });
            } else {
                m_simulations[index].simulate(endTime, std::nullopt);
            }
        };

        if (num_Threads <= 0) {
            // Run on all available threads
            std::vector threads = std::vector<std::thread>(count);

            for (size_t i = 0; i < count; ++i) {
                threads[i] = std::thread(runSimulation, i);
            }

            for (std::thread &thread : threads) {
                thread.join();
            }
        } else {
            // Run on specified number of threads
            ThreadPool threadPool{num_Threads};

            for (size_t i = 0; i < count; ++i) {
                threadPool.addTask([runSimulation, i]() {
                    runSimulation(i);
                });
            }
        }
    }
    void ParallelRunner::setCallback(const std::function<void(size_t, const Simulation&)> &callback) {
        m_callback = callback;
    }
} // SpStochLib