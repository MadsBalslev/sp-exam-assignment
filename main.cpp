#include "FileWriter.cpp"
#include "Agent.cpp"
#include "examples/Simple.cpp"
#include "examples/Seihr.cpp"
#include "examples/Circadian.cpp"
#include "Plotting/TrajectoryDrawer.cpp"
#include "Plotting/ReactionDrawer.cpp"

using namespace SpStochLib;
using namespace SpStochLib::Plots;


int main() {
    auto example1 = Examples::simple();
    auto example2 = Examples::circadian();
    auto example3 = Examples::seihr(10000);

    ReactionDrawer::draw(example1, "simple");
    ReactionDrawer::draw(example2, "circadian");
    ReactionDrawer::draw(example3, "seihr");

    return 0;
}