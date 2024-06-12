#include "doctest/doctest.h"
#include "Reaction.h"
#include "Agent.h"

using namespace SpStochLib;

// 9. Implement unit tests (e.g. test symbol table methods, their failure cases, and pretty-printing of reaction rules).

TEST_SUITE("Reaction Tests") {
    TEST_CASE("Test pretty printing") {
        Reaction reaction;

        Agent a = Agent("A", 1);
        Agent c = Agent("C", 1);
        Agent b = Agent("B", 0);

        reaction.addReactant(a);
        reaction.addReactant(c);
        reaction.addProduct(b);
        reaction.addProduct(c);

        reaction.rate = 50.0;

        CHECK(reaction.name() == "A + C -> B + C (rate = 50)");
    }
}
