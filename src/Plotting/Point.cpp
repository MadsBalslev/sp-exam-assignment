#include "Point.h"

namespace SpStochLib::Plots {
    Point::Point(double time, double amount) {
        x = time;
        y = amount;
    }

    double Point::getX() {
        return x;
    }

    double Point::getY() {
        return y;
    }
}
