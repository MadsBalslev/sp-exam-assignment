#include "Estimate.cpp"
#include <iostream>

using namespace SpStochLib::Estimation;

// 8. Implement support for multiple computer cores by parallelizing the computation of several simulations at the same time.
// Estimate the likely (average) value of the hospitalized peak over 100 simulations.

int main() {
    auto N_DK =  5822763;
    auto N_NJ = 589755;

    auto DkResult = estimatePeakMean(N_DK, 100, 1);
    auto NjResult = estimatePeakMean(N_NJ, 100, 1);

    std::cout << "Peak DK hospitalized: " << DkResult.first << std::endl;
    std::cout << "Mean DK hospitalized: " << DkResult.second << std::endl;
    std::cout << "Peak NJ hospitalized: " << NjResult.first << std::endl;
    std::cout << "Mean NJ hospitalized: " << NjResult.second << std::endl;

    return 0;
}
