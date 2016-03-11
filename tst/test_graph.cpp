#include "catch.hpp"

#include "graph.hpp"
#include <algorithm>

TEST_CASE("Edge adding and removing", "[graph]")
{
    Graph<> g(4);

    std::vector<typename Graph<>::edge_t> edges =
    {
        {0, 1}, {2, 3}
    };

    // Step 1
    for (const auto &e : edges)
        g.add_edge(e);

    auto g_edges = g.edges();

    REQUIRE(g_edges.size() == edges.size());
    REQUIRE(std::equal(g_edges.begin(), g_edges.end(), edges.begin()));

    // Step 2
    g.remove_edge({0, 1});
    g_edges = g.edges();

    REQUIRE(g_edges.size() == 1);
    REQUIRE(g_edges[0].start == 2);
    REQUIRE(g_edges[0].stop == 3);
}
