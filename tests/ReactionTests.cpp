#include "doctest/doctest.h"
#include "Reaction.h"
#include "Agent.h"

using namespace SpStochLib;

TEST_SUITE("Reaction Tests") {
    TEST_CASE("Test pretty printing") {
        Reaction reaction;
        reaction.addReactant(Agent("A", 1));
        reaction.addReactant(Agent("C", 1));
        reaction.addProduct(Agent("B", 0));
        reaction.addProduct(Agent("C", 0));

        reaction.rate = 50.0;

        CHECK(reaction.name() == "A + C -> B + C (rate = 50)");
    }
}
