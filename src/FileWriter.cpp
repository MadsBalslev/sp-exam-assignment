#include "FileWriter.h"

namespace SpStochLib {
    FileWriter::FileWriter(const SpStochLib::Simulation &simulation, const std::string &fileName) {
        m_outputFile = std::make_unique<std::ofstream>(fileName);

        for (const auto &species : simulation.agents()) {
            *m_outputFile << species.second->name() << ",";
        }

        *m_outputFile << "Time\n";
    }

    FileWriter::~FileWriter() {
        m_outputFile->close();
    }

    void FileWriter::write(const Simulation &simulation) {
        for (const auto &agent : simulation.agents()) {
            std::cout << agent.second->name() << ": "<< agent.second->amount() << std::endl;
            *m_outputFile << agent.second->amount() << ",";
        }

        *m_outputFile << simulation.time() << "\n";
    }
} // SpStochLib