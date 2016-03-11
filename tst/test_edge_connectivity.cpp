#include "catch.hpp"

#include <algorithm>

#include "edge_connectivity.hpp"
#include "graph.hpp"

TEST_CASE("Petersen's graph", "[edge_connectivity]")
{
    int size = 10;
    std::vector<edge_base_t> petersen_graph =
    {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {1, 8}, {2, 6}, {3, 9}, {7, 4}, {0, 5},
        {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 5}
    };

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int c = get_edge_connectivity(i, j, size, petersen_graph);
            REQUIRE(c == 3);
        }
    }
}
