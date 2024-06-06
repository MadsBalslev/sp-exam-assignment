#include "Simulation.h"

namespace SpStochLib {
    bool Simulation::canReact(Reaction &reaction) {
        return std::all_of(
                reaction.reactants().begin(),
                reaction.reactants().end(),
                [](const auto &reactant) { return reactant.amount() > 0;}
        );
    };

    void Simulation::react(Reaction &reaction) {
        for(auto &reactant : reaction.reactants()) {
            Agent agent = reactant;
            agent.decreaseAmount(1);
        }

        for(auto &reactant : reaction.products()) {
            Agent product = reactant;
            product.addAmount(1);
        }
    }

    double Simulation::time() const {
        return m_time;
    }
}