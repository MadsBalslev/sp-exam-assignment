#include "doctest/doctest.h"
#include "SymbolTable.hpp"

using namespace SpStochLib;

TEST_SUITE("SymbolTable") {
    TEST_CASE("Adding and getting a symbol") {
        SymbolTable<int> table;
        table.add("a", 1);
        table.add("b", 2);
        table.add("c", 3);

        CHECK(table["a"] == 1);
        CHECK(table["b"] == 2);
        CHECK(table["c"] == 3);
        CHECK_THROWS(table["d"]);
    }

    TEST_CASE("Modifying symbols") {
        SymbolTable<int> table;

        table.add("a", 1);
        table.add("b", 2);
        table.add("c", 3);

        table["a"] = 4;
        table["b"] = 5;
        table["c"] = 6;

        CHECK(table["a"] == 4);
        CHECK(table["b"] == 5);
        CHECK(table["c"] == 6);
    }

    TEST_CASE("SymbolTable - Removing") {
        SymbolTable<int> table;

        table.add("a", 1);
        table.add("b", 2);
        table.add("c", 3);

        table.remove("a");
        table.remove("b");
        table.remove("c");

        CHECK_THROWS(table["a"]);
        CHECK_THROWS(table["b"]);
        CHECK_THROWS(table["c"]);
    }

    TEST_CASE("SymbolTable - Iteration") {
        SymbolTable<int> table;

        table.add("a", 1);
        table.add("b", 2);
        table.add("c", 3);

        int sum = 0;

        for(auto& [key, value] : table) {
            sum += *value;
        }

        CHECK(sum == 6);
    }

    TEST_CASE("Add existing symbol throws error") {
        SymbolTable<int> table;

        table.add("a", 1);

        CHECK_THROWS(table.add("a", 2));
    }

}
