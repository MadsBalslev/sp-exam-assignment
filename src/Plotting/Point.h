#ifndef SPSTOCHLIB_POINT_H
#define SPSTOCHLIB_POINT_H

namespace SpStochLib::Plots {
    class Point {
        double x;
        double y;

    public:
        Point(double time, double amount);
        double getX();
        double getY();
    };
}


#endif //SPSTOCHLIB_POINT_H
