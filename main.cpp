#include "FileWriter.cpp"
#include "Agent.cpp"
#include "examples/Simple.cpp"
#include "examples/Seihr.cpp"
#include "examples/Circadian.cpp"
#include "Plotting/TrajectoryDrawer.cpp"

using namespace SpStochLib;
using namespace SpStochLib::Plots;


int main() {
    auto example1_1 = Examples::simple(100, 0, 1);
    auto example1_2 = Examples::simple(100, 0, 2);
    auto example1_3 = Examples::simple(50, 50, 1);
    auto example2 = Examples::circadian();
    auto example3 = Examples::seihr(10000);

    TrajectoryDrawer simpleDrawer1 = TrajectoryDrawer();
    TrajectoryDrawer simpleDrawer2 = TrajectoryDrawer();
    TrajectoryDrawer simpleDrawer3 = TrajectoryDrawer();
    TrajectoryDrawer circadianDrawer = TrajectoryDrawer();
    TrajectoryDrawer seihrDrawer = TrajectoryDrawer();


    example1_1.simulate(2000, [&simpleDrawer1](const Simulation &simulation) {
        simpleDrawer1.addToGraph(simulation);
    });

    example1_2.simulate(2000, [&simpleDrawer2](const Simulation &simulation) {
        simpleDrawer2.addToGraph(simulation);
    });

    example1_3.simulate(2000, [&simpleDrawer3](const Simulation &simulation) {
        simpleDrawer3.addToGraph(simulation);
    });

    example2.simulate(100, [&circadianDrawer](const Simulation &simulation) {
        circadianDrawer.addToGraph(simulation);
    });

    example3.simulate(100, [&seihrDrawer](const Simulation &simulation) {
        seihrDrawer.addToGraph(simulation);
    });

    simpleDrawer1.draw(2000, "simple1");
    simpleDrawer2.draw(2000, "simple2");
    simpleDrawer3.draw(2000, "simple3");
    circadianDrawer.draw(100, "circadian");
    seihrDrawer.draw(100, "seihr");


    return 0;
}