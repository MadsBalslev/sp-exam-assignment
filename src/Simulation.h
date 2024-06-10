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
        std::unique_ptr<SymbolTable<Reaction>> m_reactions = std::make_unique<SymbolTable<Reaction>>();
        std::unique_ptr<SymbolTable<Agent>> m_agents = std::make_unique<SymbolTable<Agent>>();
        std::unique_ptr<Agent> env = std::make_unique<Agent>("env", 0);

        static bool canReact(Reaction& reaction);
        static void react(Reaction& reaction);
        Reaction& getMinDelayReaction();

    public:
        Agent& addAgent(const std::string &name, size_t amount);
        void addReaction(Reaction &&reaction, double rate);

        [[nodiscard]] double time() const;
        [[nodiscard]] SymbolTable<Reaction>& reactions() const;
        [[nodiscard]] SymbolTable<Agent>& agents() const;
        [[nodiscard]] Agent& environment() const;

        void simulate(double endTime, std::optional<std::function<void(const Simulation &)>> callback);

        friend std::ostream &operator<<(std::ostream &os, const Simulation &simulation);
    };
}

#endif //SPSTOCHLIB_SIMULATION_H
