#include "TrajectoryDrawer.h"
#include "Point.cpp"
#include "sciplot/sciplot.hpp"

namespace SpStochLib::Plots {
    void TrajectoryDrawer::addToGraph(const SpStochLib::Simulation &sim) {
        // For each line in sim add to correct linedata
        for (const auto &agent : sim.agents()) {
            // Check if agent already in lines
            auto entry = lines.find(agent.first);
            Point point = Point(sim.time(), agent.second->amount());

            // If not create entry and add agent.amount
            if (entry == lines.end()) {
                std::vector<Point> points {point};
                auto inserted = lines.insert({agent.first, points});
            } else {
                entry->second.push_back(point);
            }
        }
    }

    void TrajectoryDrawer::draw(double endTime, const std::string filename, bool showPlot = false) {
        using namespace sciplot;

        // Create a Plot object
        Plot2D plot;

        // Set the x and y labels
        plot.xlabel("Time");
        plot.ylabel("Count");

        // Set the x and y ranges
        plot.xrange(0.0, endTime);

        // Set the legend to be on the bottom along the horizontal
        plot.legend()
                .atOutsideBottom()
                .displayHorizontal()
                .displayExpandWidthBy(2);

        for (auto& entry : lines) {
            auto name = entry.first;
            auto points = entry.second;

            bool scale = false;

            if(name == "H") {
                scale = true;
                name += " * 1000";
            }

            std::vector<double> pXs;
            std::vector<double> pYs;


            for (auto& point : points) {
                pXs.push_back(point.getX());
                if(scale) {
                    pYs.push_back(point.getY() * 1000);
                } else {
                    pYs.push_back(point.getY());
                }
            }
            std::cout << "Drawing " << name << std::endl;
            std::cout << "Xs: " << pXs.size() << std::endl;
            std::cout << "Ys: " << pYs.size() << std::endl;

            plot.drawCurve(pXs, pYs).label(name);

        }

        // Create figure to hold plot
        Figure fig = {{plot}};
        // Create canvas to hold figure
        Canvas canvas = {{fig}};
        canvas.size(1500, 1000);

        // Save the plot to a PDF file
        canvas.save(filename + ".png");

        if(showPlot) {
            canvas.show();
        }


    }
}