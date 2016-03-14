#include <fstream>
#include <iostream>

#include "connectivity_pairs.hpp"
#include "load_graph.hpp"
#include "estd.hpp"

void print_usage()
{
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        print_usage();
        return 1;
    }

    const auto input_filename = argv[1];
    std::ifstream input(input_filename);
    std::string line;

    int line_num = 0;
    while (input.good())
    {
        std::getline(input, line);
        if (line != "")
        {
            auto g = load_graph(estd::mut(input));
            auto edges = g.edges();

            // making the graph undirected
            for (const auto &e : edges)
                g.add_edge({e.stop, e.start});

            std::cout << "Graph #" << line_num << std::endl;
            for (int i = 0; i < g.size(); i++)
                for (int j = i + 1; j < g.size(); j++)
                {
                    std::cout << "cp for " << i << " <-> " << j << ": ";
                    for (const auto &cp : get_connectivity_pairs(g, i, j))
                        std::cout << "(" << cp.first << ", " << cp.second << ") ";
                    std::cout << std::endl;
                }
            std::cout << "--\n";
        }

        line_num++;
    }

    return 0;
}
