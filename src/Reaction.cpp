#include "Reaction.h"
#include <random>

namespace SpStochLib {

    ReactionCompounds &Reaction::reactants() {
        return m_reactants;
    }

    ReactionCompounds &Reaction::products() {
        return m_products;
    }

    std::string Reaction::name() const {
        std::stringstream ss;
        ss << m_reactants << " -> " << m_products << " (rate = " << rate << ")";

        return ss.str();
    };


    void Reaction::addProduct(const Agent &product) {
        m_products.addAgent(product);
    };

    void Reaction::addReactant(const Agent &reactant) {
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

    std::ostream &operator<<(std::ostream &os, Reaction &reaction) {
        return os << reaction.name();
    };

    // A + B -> C
    Reaction operator>>=(ReactionCompounds &&compounds, const Agent &agent) {
        Reaction reaction;

        for(const auto &a : compounds.agents()) {
            reaction.addReactant(a);
        }

        reaction.addProduct(agent);

        return reaction;
    };

    // A -> B + C
    Reaction operator>>=(const Agent &agent, ReactionCompounds &&compounds) {
        Reaction reaction;
        reaction.addReactant(agent);

        for(const auto &a : compounds.agents()) {
            reaction.addProduct(a);
        }

        return reaction;

    };
    // A + B -> C + D
    Reaction operator>>= (const ReactionCompounds &compoundsL, const ReactionCompounds &compoundsR) {
        Reaction reaction;

        for(const auto &a : compoundsL.agents()) {
            reaction.addReactant(a);
        }
        for(const auto &a : compoundsR.agents()) {
            reaction.addProduct(a);
        }

        return reaction;
    };

    // A -> B
    Reaction operator>>=(const Agent &agentL, const Agent &agentR) {
        Reaction reaction;

        reaction.addReactant(agentL);
        reaction.addProduct(agentR);
        return reaction;
    };

}