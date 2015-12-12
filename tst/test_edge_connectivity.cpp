#include <iostream>
#include <algorithm>

#include "edge_connectivity.hpp"
#include "graph.hpp"

int main()
{
    int size = 10;
    std::vector<edge_base_t> petersen_graph =
    {
        edge_base_t{0, 1},
        edge_base_t{1, 2},
        edge_base_t{2, 3},
        edge_base_t{3, 4}, 
        edge_base_t{4, 0},
        edge_base_t{1, 8},
        edge_base_t{2, 6},
        edge_base_t{3, 9},
        edge_base_t{7, 4},
        edge_base_t{0, 5},
        edge_base_t{5, 6},
        edge_base_t{6, 7},
        edge_base_t{7, 8},
        edge_base_t{8, 9},
        edge_base_t{9, 5}
    };

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            std::cout << i << " and " << j << " are " << get_edge_connectivity(i, j, size, petersen_graph) << " connected.\n";
        }
    }

    return 0;
}
