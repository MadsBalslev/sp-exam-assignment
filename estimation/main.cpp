#include "Estimate.cpp"
#include <iostream>

using namespace SpStochLib::Estimation;

int main() {
    auto N_DK =  5822763;
    auto N_NJ = 589755;

    auto DkResult = estimatePeakMean(N_DK, 100);
    auto NjResult = estimatePeakMean(N_NJ, 100);

    std::cout << "Peak DK hospitalized: " << DkResult.first << std::endl;
    std::cout << "Mean DK hospitalized: " << DkResult.second << std::endl;
    std::cout << "Peak NJ hospitalized: " << NjResult.first << std::endl;
    std::cout << "Mean NJ hospitalized: " << NjResult.second << std::endl;

    return 0;
}
