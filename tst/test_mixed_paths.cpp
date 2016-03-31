
#include "catch.hpp"

#include "mixed_paths.hpp"
#include "extraordinary_graphs.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream &os, const std::vector<std::pair<int, int>> &v)
{
    for (auto p : v)
        os << "(" << p.first << ", " << p.second << ") ";

    return os;
}


TEST_CASE("A cycle with two chords", "[mixed_paths]")
{
    SimpleGraph g(6);

    for (int i = 0; i < 6; i++)
    {
        g.add_edge({i, (i + 1) % 6});
    }
    g.add_edge({0, 2});
    g.add_edge({1, 3});

    auto res = get_mixed_paths_count(g, 0, 3);
    std::vector<std::pair<int, int>> expected =
    {
        {0, 3}, {1, 2}, {2, 1}, {3, 0}, {4, 0}
    };

    REQUIRE(res.size() == expected.size());
    REQUIRE(std::equal(res.begin(), res.end(), expected.begin()));
}


TEST_CASE("Mixed path's for Petersen's graph", "[mixed_paths]")
{
    SimpleGraph g(10);
    for (const auto &e : petersen_graph_e)
    {
        g.add_edge(e);
    }

    auto res = get_mixed_paths_count(g, 0, 6);
    std::vector<std::pair<int, int>> expected =
    {
        {0, 3}, {1, 2}, {2, 1}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}
    };

    REQUIRE(res.size() == expected.size());
    REQUIRE(std::equal(res.begin(), res.end(), expected.begin()));
}
