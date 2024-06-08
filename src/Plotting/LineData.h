#ifndef SPSTOCHLIB_LINEDATA_H
#define SPSTOCHLIB_LINEDATA_H

#include <string>
#include "vector"
#include "Point.h"

namespace SpStochLib::Plots {

    class LineData {
        std::string name;
        std::vector<Point> plotPoints;

    public:
        void addplot(std::string name, Point point);
    };

}


#endif //SPSTOCHLIB_LINEDATA_H
