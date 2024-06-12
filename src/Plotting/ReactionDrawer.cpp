#include "ReactionDrawer.h"

namespace SpStochLib::Plots {
    // 2. Provide pretty-printing of the reaction network in b) network graph (e.g. Fig. 4).
    std::string ReactionDrawer::round(double& num) {
        std::ostringstream out;
        out << std::setprecision(9) << std::fixed << num;
        std::string truncated = out.str();
        truncated.erase(truncated.find_last_not_of('0') + 1, std::string::npos);

        if (truncated.back() == '.') {
            truncated.pop_back();
        }

        return truncated;
    }

    void ReactionDrawer::createNode(Agraph_t *graph, const std::string &name, const std::string &fillColor,
                                    const std::string &shape) {
        Agnode_t *node = agnode(graph, const_cast<char *>(name.c_str()), 1);
        agsafeset(node, (char *) "style", (char *) "filled", (char *) "");
        agsafeset(node, (char *) "fillcolor", (char *) fillColor.c_str(), (char *) "");
        agsafeset(node, (char *) "shape", (char *) shape.c_str(), (char *) "");
    }

    void ReactionDrawer::createEdge(Agraph_t *agraph, const std::string &source, const std::string &destination) {
        if (source == "env" || destination == "env") {
            return;
        }

        agedge(agraph, agnode(agraph, const_cast<char *>(source.c_str()), 1),
               agnode(agraph, const_cast<char *>(destination.c_str()), 1), nullptr, 1);
    }

    void ReactionDrawer::draw(SpStochLib::Simulation &simulation, const std::string &fileName) {
        GVC_t *gvc = gvContext();
        Agraph_t *g = agopen((char*)"g", Agdirected, nullptr);

        // Create species nodes
        for (const auto &[_, species]: simulation.agents()) {
            if (species->name() != "env") {
                createNode(g, species->name(), "lightblue");
            }
        }

        // Draw edges between species based on reactions
        int rateNodeCount = 0;

        for (const auto &[reactionName, reaction]: simulation.reactions()) {
            // Create rate node
            double rate = reaction->rate;

            std::string rateStr = round(rate);
            std::string rateNodeName = "rate" + std::to_string(rateNodeCount++);

            createNode(g, rateNodeName, "orange", "box");
            agset(agnode(g, (char *) rateNodeName.c_str(), 1), (char*)"label", (char*)rateStr.c_str());

            // Draw edges between every species in the reaction as well as the rate node
            for (auto &x: reaction->reactants()) {
                createEdge(g, x.get().name(), rateNodeName);
            }

            for (const auto &x: reaction->products()) {
                createEdge(g, rateNodeName, x.get().name());
            }
        }

        gvLayout(gvc, g, const_cast<char *>("dot"));
        gvRenderFilename(gvc, g, const_cast<char *>("png"), const_cast<char *>((fileName + ".png").c_str()));
        gvFreeLayout(gvc, g);
        agclose(g);
        gvFreeContext(gvc);
    }
}
