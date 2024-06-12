#ifndef SPSTOCHLIB_SYMBOLTABLE_HPP
#define SPSTOCHLIB_SYMBOLTABLE_HPP
#include <unordered_map>
#include <optional>
#include "string"
#include "memory"
#include <stdexcept>
#include <any>

// 3. Implement a generic symbol table to store and lookup objects of user-defined key and value types.
// Support failure cases when a) the table does not contain a looked up symbol, b) the table already contains a symbol that is being added.
// Demonstrate the usage of the symbol table with the reactants (names and initial counts).

namespace SpStochLib {

    template<typename T>
    class SymbolTable {
        std::unordered_map<std::string, std::unique_ptr<T>> m_table;

        bool checkExists(const std::string &symbol) { return m_table.find(symbol) != m_table.end(); };

    public:
        T& add(const std::string &symbol, T &&object) {
            if(!checkExists(symbol)) {
                // Add
                auto ptr = std::make_unique<T>(std::move(object));
                auto& ref = *ptr;
                m_table[symbol] = std::move(ptr);

                return ref;
            } else {
                // Throw error
                throw std::runtime_error("The symbol already exists in the table");
            }
        };

        void remove(const std::string &symbol) {
            if(checkExists(symbol)) {
                // Add
                m_table.erase(symbol);
            } else {
                throw std::runtime_error("The symbol does not exist in the table");
            }
        };

        T* get(const std::string &symbol) {
            if(checkExists(symbol)) {

                return m_table.find(symbol)->second.get();
            }
            throw std::runtime_error("The symbol does not exist in the table");
        };

        T& operator[](const std::string &symbol) {
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
