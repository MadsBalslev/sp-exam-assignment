#ifndef SPSTOCHLIB_SYMBOLTABLE_HPP
#define SPSTOCHLIB_SYMBOLTABLE_HPP
#include <unordered_map>
#include <optional>
#include "string"
#include "memory"
#include <stdexcept>
#include <any>

namespace SpStochLib {

    template<class KT, class VT>
    class SymbolTable {
        std::unordered_map<KT, std::unique_ptr<VT>> m_table;

        bool checkExists(const KT &symbol) { return m_table.find(symbol) != m_table.end(); };

    public:
        VT& add(const KT &symbol, VT &&object) {
            if(!checkExists(symbol)) {
                // Add
                auto ptr = std::make_unique<VT>(std::move(object));
                auto& ref = *ptr;
                m_table[symbol] = std::move(ptr);

                return ref;
            } else {
                // Throw error
                throw std::runtime_error("The symbol already exists in the table");
            }
        };

        void remove(const KT &symbol) {
            if(!checkExists(symbol)) {
                // Add
                m_table.erase(symbol);
            } else {
                throw std::runtime_error("The symbol does not exist in the table");
            }
        };

        VT* get(const KT &symbol) {
            if(checkExists(symbol)) {

                return m_table.find(symbol)->second.get();
            }
            throw std::runtime_error("The symbol does not exist in the table");
        };

        VT& operator[](const KT &symbol) {
            auto item = get(symbol);

            return *item;
        };

        auto begin() { return m_table.begin(); }
        auto end() { return m_table.end(); }
        auto begin() const { return m_table.begin(); }
        auto end() const { return m_table.end(); }
    };
}


#endif //SPSTOCHLIB_SYMBOLTABLE_HPP
