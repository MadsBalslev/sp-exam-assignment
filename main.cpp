#include "FileWriter.cpp"
#include "Agent.cpp"
#include "examples/Simple.cpp"
#include "examples/Seihr.cpp"
#include "examples/Circadian.cpp"
#include "Plotting/TrajectoryDrawer.cpp"
#include "Plotting/ReactionDrawer.cpp"

using namespace SpStochLib;
using namespace SpStochLib::Plots;

// 5. Demonstrate the application of the library on the three examples (shown in Fig. 1, 2, 3).

int main() {
    auto example1 = Examples::simple();
    auto example2 = Examples::circadian();
    auto example3 = Examples::seihr(10000);

    // 2. Provide pretty-printing of the reaction network in b) network graph (e.g. Fig. 4).
    ReactionDrawer::draw(example1, "simple");
    ReactionDrawer::draw(example2, "circadian");
    ReactionDrawer::draw(example3, "seihr");

    TrajectoryDrawer drawer1;
    TrajectoryDrawer drawer2;
    TrajectoryDrawer drawer3;

    example1.simulate(2000, [&drawer1](const Simulation& simulation) {
        drawer1.addToGraph(simulation);
    });

    example2.simulate(100, [&drawer2](const Simulation& simulation) {
        drawer2.addToGraph(simulation);
    });

    example3.simulate(100, [&drawer3](const Simulation& simulation) {
        drawer3.addToGraph(simulation);
    });
    // 6. Display simulation trajectories of how the amounts change. External tools/libraries can be used to visualize.
    drawer1.draw(2000, "simple");
    drawer2.draw(100, "circadian");
    drawer3.draw(100, "seihr");

    return 0;
}