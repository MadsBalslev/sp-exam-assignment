#include <stdexcept>
#include "Agent.h"

namespace SpStochLib {

    Agent::Agent(std::string name, size_t quantity) {};

    std::string Agent::name() const {
        return m_name;
    }

    size_t Agent::quantity() const {
        return m_amount;
    }

    void Agent::addAmount(size_t amount) {
        m_amount += amount;
    }

    void Agent::decreaseAmount(size_t amount) {
        m_amount -= amount;
    }
}
