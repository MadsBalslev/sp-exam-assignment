#include "Reaction.h"
#include <random>

namespace SpStochLib {


    void Reaction::addProduct(Agent &product) {
        m_products.addAgent(product);
    };

    void Reaction::addReactant(Agent &reactant) {
        m_reactants.addAgent(reactant);
    };

    void Reaction::computeDelay(std::mt19937 &generator) {
        double lambda = rate;

        for(auto &agent : reactants()) {
            lambda *= static_cast<double>(agent.amount());
        }

        std::exponential_distribution<double> distribution(lambda);
        delay = distribution(generator);
    };

    // A + B -> C
    Reaction operator>>=(ReactionCompounds &&compounds, Agent &agent) {
        Reaction reaction;

        for(auto a : compounds.agents()) {
            reaction.addReactant(a);
        }

        reaction.addProduct(agent);

        return reaction;
    };
    // A -> B
    Reaction operator>>=(Agent &agentL,Agent &agentR) {
        Reaction reaction;

        reaction.addReactant(agentL);
        reaction.addProduct(agentR);
        return reaction;
    };
    // A -> B + C
    Reaction operator>>=(Agent &agent, ReactionCompounds &&compounds) {
        Reaction reaction;
        reaction.addReactant(agent);

        for(auto a : compounds.agents()) {
            reaction.addProduct(a);
        }

        return reaction;

    };
    // A + B -> C + D
    Reaction operator>>= (ReactionCompounds &compoundsL, ReactionCompounds &compoundsR) {
        Reaction reaction;

        for(auto a : compoundsL.agents()) {
            reaction.addReactant(a);
        }
        for(auto a : compoundsR.agents()) {
            reaction.addProduct(a);
        }

        return reaction;
    };



}