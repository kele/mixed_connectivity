#include "catch.hpp"
#include "connectivity_pairs.hpp"
#include "graph.hpp"


TEST_CASE("A cycle with two chords [connectivity pairs]", "[connectivity_pairs]")
{
    SimpleGraph g(6);

    for (int i = 0; i < 6; i++)
    {
        g.add_edge({i, (i + 1) % 6});
    }
    g.add_edge({0, 2});
    g.add_edge({3, 1});

    auto res = get_connectivity_pairs(g, 0, 3);

    std::vector<std::pair<int, int>> expected =
    {
        {0, 3}, {1, 2}, {2, 1}, {3, 0}, {4, 0}
    };

    REQUIRE(res.size() == expected.size());
    REQUIRE(std::equal(res.begin(), res.end(), expected.begin()));
}
