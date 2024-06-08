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

        auto& env = simulation.environment();

        auto& DA = simulation.addAgent("DA", 1);
        auto& D_A = simulation.addAgent("D_A", 0);
        auto& DR = simulation.addAgent("DR", 1);
        auto& D_R = simulation.addAgent("D_R", 0);
        auto& MA = simulation.addAgent("MA", 0);
        auto& MR = simulation.addAgent("MR", 0);
        auto& A = simulation.addAgent("A", 0);
        auto& R = simulation.addAgent("R", 0);
        auto& C = simulation.addAgent("C", 0);

        simulation.addReaction(A + DA >>= D_A, gammaA);
        simulation.addReaction(D_A >>= DA + A, thetaA);
        simulation.addReaction(A + DR >>= D_R, gammaR);
        simulation.addReaction(D_R >>= DR + A, thetaR);
        simulation.addReaction(D_A >>= MA + D_A, alpha_A);
        simulation.addReaction(DA >>= MA + DA, alphaA);
        simulation.addReaction(D_R >>= MR + D_R, alpha_R);
        simulation.addReaction(DR >>= MR + DR, alphaR);
        simulation.addReaction(MA >>= MA + A, betaA);
        simulation.addReaction(MR >>= MR + R, betaR);
        simulation.addReaction(A + R >>= C, gammaC);
        simulation.addReaction(C >>= R, deltaA);
        simulation.addReaction(A >>= env, deltaA);
        simulation.addReaction(R >>= env, deltaR);
        simulation.addReaction(MA >>= env, deltaMA);
        simulation.addReaction(MR >>= env, deltaMR);

        return simulation;
    }
}

#endif