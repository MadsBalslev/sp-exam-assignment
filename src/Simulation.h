#ifndef SPSTOCHLIB_SIMULATION_H
#define SPSTOCHLIB_SIMULATION_H

#include <Reaction.h>
#include <algorithm>
#include <fstream>
#include <random>
#include <functional>
#include "Reaction.h"
#include "Agent.h"
#include "ReactionCompounds.h"
#include "SymbolTable.hpp"


namespace SpStochLib {

    class Simulation {
        double m_time = 0;
        std::unique_ptr<SymbolTable<std::string, Reaction>> m_reactions = std::make_unique<SymbolTable<std::string, Reaction>>();
        std::unique_ptr<SymbolTable<std::string, Agent>> m_agents = std::make_unique<SymbolTable<std::string, Agent>>();

        bool canReact(Reaction& reaction);
        void react(Reaction& reaction);
        Reaction& getMinDelayReaction();

    public:
        Agent& addAgent(const std::string &name, size_t amount);
        void addReaction(Reaction &&reaction, double rate);

        [[nodiscard]] double time() const;
        [[nodiscard]] SymbolTable<std::string, Reaction>& reactions() const;
        [[nodiscard]] SymbolTable<std::string, Agent>& agents() const;

        void simulate(double endTime, std::optional<std::function<void(const Simulation &)>> callback);

        friend std::ostream &operator<<(std::ostream &os, const Simulation &simulation);
    };
}

#endif //SPSTOCHLIB_SIMULATION_H
