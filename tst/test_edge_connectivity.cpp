#include "catch.hpp"

#include <algorithm>

#include "edge_connectivity.hpp"
#include "graph.hpp"
#include "extraordinary_graphs.hpp"

TEST_CASE("Petersen's graph", "[edge_connectivity]")
{
    int size = 10;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int c = get_edge_connectivity(i, j, size, petersen_graph_e);
            REQUIRE(c == 3);
        }
    }
}
