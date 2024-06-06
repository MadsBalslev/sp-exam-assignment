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
    }

    std::ostream &operator<<(std::ostream &os, Reaction &reaction) {
        return os << reaction.name();
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
    Reaction operator>>=(Agent &agentL, Agent &agentR) {
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