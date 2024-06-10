#include "FileWriter.cpp"
#include "Agent.cpp"
#include "examples/Simple.cpp"
#include "examples/Seihr.cpp"
#include "examples/Circadian.cpp"
#include "Plotting/TrajectoryDrawer.cpp"

using namespace SpStochLib;
using namespace SpStochLib::Plots;


int main() {
    auto example1 = Examples::simple();
    auto example2 = Examples::circadian();
    auto example3 = Examples::seihr(10000);

    TrajectoryDrawer simpleDrawer = TrajectoryDrawer();
    TrajectoryDrawer circadianDrawer = TrajectoryDrawer();
    TrajectoryDrawer seihrDrawer = TrajectoryDrawer();


    example1.simulate(2000, [&simpleDrawer](const Simulation &simulation) {
        simpleDrawer.addToGraph(simulation);
    });

    example2.simulate(100, [&circadianDrawer](const Simulation &simulation) {
        circadianDrawer.addToGraph(simulation);
    });

    example3.simulate(100, [&seihrDrawer](const Simulation &simulation) {
        seihrDrawer.addToGraph(simulation);
    });

    simpleDrawer.draw(2000, "simple");
    circadianDrawer.draw(100, "circadian");
    seihrDrawer.draw(100, "seihr");


    return 0;
}