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

    Agent& Simulation::environment() const {
        return *env;
    }

    double Simulation::time() const {
        return m_time;
    }

    void Simulation::simulate(const double endTime, std::optional<std::function<void(const Simulation &)>> callback) {
        std::random_device random;
        std::mt19937 generator(random());
        while(m_time <= endTime) {
            for (auto &[_, reaction] : *m_reactions) {
                reaction->computeDelay(generator);
            }

            Reaction& minDelayReaction = getMinDelayReaction();
            m_time += minDelayReaction.delay;

            if(canReact(minDelayReaction)) {
                react(minDelayReaction);
            }

            if(callback) {
                (*callback)(*this);
            }
        }

        if(!callback) {
            std::cout << *this;
        }
    }

    Reaction &Simulation::getMinDelayReaction() {
        auto getMin = std::min_element(m_reactions->begin(), m_reactions->end(),
                       [](const auto &a, const auto &b) {
                                return a.second->delay < b.second->delay;
                            }
                       );
        return *getMin->second;
    }

    Agent& Simulation::addAgent(const std::string &name, size_t amount) {
        Agent agent = Agent{name, amount};
        return m_agents->add(name, std::move(agent));
    }

    void Simulation::addReaction(Reaction &&reaction, double rate) {
        reaction.rate = rate;
        m_reactions->add(reaction.name(), std::move(reaction));
    };

    SymbolTable<std::string, Reaction> &Simulation::reactions() const {
        return *m_reactions;
    }

    SymbolTable<std::string, Agent> &Simulation::agents() const {
        return *m_agents;
    }

    std::ostream &operator<<(std::ostream &os, const Simulation &simulation) {
        for (const auto &[_, reaction]: simulation.reactions()) {
            os << reaction->name();
            os << std::endl;
        }

        return os;
    }
}