#ifndef SPSTOCHLIB_FILEWRITER_H
#define SPSTOCHLIB_FILEWRITER_H

#include "Simulation.h"

namespace SpStochLib {

    class FileWriter {
        std::unique_ptr<std::ofstream> m_outputFile;

    public:
        FileWriter(const Simulation& simulation, const std::string& fileName);
        ~FileWriter();

        void write(const Simulation& simulation);
    };

} // SpStochLib

#endif //SPSTOCHLIB_FILEWRITER_H
