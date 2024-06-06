#ifndef SPSTOCHLIB_AGENT_H
#define SPSTOCHLIB_AGENT_H
#include <stdexcept>
#include "string"

namespace SpStochLib {
    class Agent {
        std::string m_name;
        size_t m_amount;

    public:
        Agent(std::string name, size_t amount);

        [[nodiscard]] std::string name() const;

        [[nodiscard]] size_t amount() const;

        void addAmount(size_t amount);

        void decreaseAmount(size_t amount);

    };
}


#endif //SP_EXAM_TRY_2_AGENT_H
