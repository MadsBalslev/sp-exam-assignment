#include "Reaction.h"
#include <random>

namespace SpStochLib {

    ReactionCompounds &Reaction::reactants() {
        return m_reactants;
    }

    ReactionCompounds &Reaction::products() {
        return m_products;
    }

    // 2. Provide pretty-printing of the reaction network in a) human readable format
    std::string Reaction::name() const {
        std::stringstream ss;
        ss << m_reactants << " -> " << m_products << " (rate = " << rate << ")";

        return ss.str();
    };


    void Reaction::addProduct(Agent &product) {
        m_products.addAgent(product);
    };

    void Reaction::addReactant(Agent &reactant) {
        m_reactants.addAgent(reactant);
    };

    void Reaction::computeDelay(std::mt19937 &generator) {
        double lambdaK = rate;

        for(auto &agent : reactants()) {
            lambdaK *= static_cast<double>(agent.get().amount());
        }

        std::exponential_distribution<double> distribution(lambdaK);
        delay = distribution(generator);
    }

    // 2. Provide pretty-printing of the reaction network in a) human readable format
    std::ostream &operator<<(std::ostream &os, Reaction &reaction) {
        return os << reaction.name();
    };

    // 1. The library should overload operators to support the reaction rule typesetting directly in C++ code.

    // A + B -> C
    Reaction operator>>=(ReactionCompounds &&compounds, Agent &agent) {
        Reaction reaction;

        for(const auto &a : compounds.agents()) {
            reaction.addReactant(a);
        }

        reaction.addProduct(agent);

        return reaction;
    };

    // A -> B + C
    Reaction operator>>=(Agent &agent, ReactionCompounds &&compounds) {
        Reaction reaction;
        reaction.addReactant(agent);

        for(const auto &a : compounds.agents()) {
            reaction.addProduct(a);
        }

        return reaction;

    };
    // A + B -> C + D
    Reaction operator>>= (ReactionCompounds &compoundsL, ReactionCompounds &compoundsR) {
        Reaction reaction;

        for( auto &a : compoundsL.agents()) {
            reaction.addReactant(a);
        }
        for(const auto &a : compoundsR.agents()) {
            reaction.addProduct(a);
        }

        return reaction;
    };

    // A -> B
    Reaction operator>>=(Agent &agentL, Agent &agentR) {
        Reaction reaction;

        reaction.addReactant(agentL);
        reaction.addProduct(agentR);
        return reaction;
    };

}