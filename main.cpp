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

    TrajectoryDrawer drawer = TrajectoryDrawer();

    FileWriter fileWriter1{example1, "simple.csv"};
    FileWriter fileWriter2{example2, "circadian.csv"};
    FileWriter fileWriter3{example3, "seihr.csv"};


    example1.simulate(2000, [&fileWriter1](const Simulation &simulation) {
        fileWriter1.write(simulation);
    });


    return 0;
}