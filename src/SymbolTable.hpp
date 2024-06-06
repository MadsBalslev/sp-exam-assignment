#ifndef SPSTOCHLIB_SYMBOLTABLE_HPP
#define SPSTOCHLIB_SYMBOLTABLE_HPP
#include <unordered_map>
#include <optional>
#include "string"
#include "memory"
#include <stdexcept>

namespace SpStochLib {

    template<typename KT, typename VT>
    class SymbolTable {
        std::unordered_map<KT, VT> m_table;

        bool checkExists(const KT &symbol) { return m_table.find(symbol) != m_table.end(); };

    public:
        VT add(const KT &symbol, VT &&object) {
            if(!checkExists(symbol)) {
                // Add
                m_table.insert(symbol, object);
            } else {
                // Throw error
                throw std::runtime_error("The symbol: [" + symbol + "] already exists in the table");
            }
            return m_table[symbol];
        };

        void remove(const KT &symbol) {
            if(!checkExists(symbol)) {
                // Add
                m_table.erase(symbol);
            } else {
                throw std::runtime_error("The symbol: [" + symbol + "] does not exists in the table");
            }
        };

        VT* get(const KT &symbol) {
            if(checkExists(symbol)) {
                return m_table[symbol];
            }
            throw std::runtime_error("The symbol: [" + symbol + "] does not exists in the table");
        };

    };
}


#endif //SPSTOCHLIB_SYMBOLTABLE_HPP
