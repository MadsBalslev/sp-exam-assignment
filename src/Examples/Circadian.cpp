#ifndef SPSTOCHLIB_CIRCADIAN_CPP
#define SPSTOCHLIB_CIRCADIAN_CPP

#include "Simulation.h"

namespace SpStochLib::Examples {
    Simulation circadian() {
        auto alphaA = 50;
        auto alpha_A = 500;
        auto alphaR = 0.01;
        auto alpha_R = 50;
        auto betaA = 50;
        auto betaR = 5;
        auto gammaA = 1;
        auto gammaR = 1;
        auto gammaC = 2;
        auto deltaA = 1;
        auto deltaR = 0.2;
        auto deltaMA = 10;
        auto deltaMR = 0.5;
        auto thetaA = 50;
        auto thetaR = 100;

        Simulation simulation{};

        auto DA = simulation.addAgent("DA", 1);
        auto D_A = simulation.addAgent("D_A", 0);
        auto DR = simulation.addAgent("DR", 1);

        return simulation;
    }
}

#endif