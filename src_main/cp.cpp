#include <iostream>

#include "process_graph_dataset.hpp"
#include "connectivity_pairs.hpp"
#include "load_graph.hpp"
#include "estd.hpp"

void process_cp(const SimpleGraph &g, int line_num)
{
    auto edges = g.edges();

    for (int i = 0; i < g.size(); i++)
        for (int j = i + 1; j < g.size(); j++)
        {
            std::cout << "Graph #" << line_num << ": ";
            std::cout << "cp for " << i << " <-> " << j << ": ";
            for (const auto &cp : get_connectivity_pairs(g, i, j))
                std::cout << "(" << cp.first << ", " << cp.second << ") ";
            std::cout << std::endl;
        }
    std::cout << "--\n";
}

int main(int argc, char *argv[])
{
    return process_main(argc, argv, process_cp);
}
