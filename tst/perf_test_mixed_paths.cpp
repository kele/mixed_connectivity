#include "catch.hpp"

#include "mixed_paths.hpp"
#include "extraordinary_graphs.hpp"

TEST_CASE("Mixed path's for Petersen's graph", "[mixed_paths]")
{
    for (int i = 0; i < 100; i++)
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
}

TEST_CASE("Mixed paths clique.", "[mixed_paths]")
{
    const int GRAPH_SIZE = 9;
    SimpleGraph g(GRAPH_SIZE);
    for (int i = 0; i < GRAPH_SIZE; i++)
        for (int j = i + 1; j < GRAPH_SIZE; j++)
            g.add_edge({i, j});

    g.remove_edge({0, 1});

    auto res = get_mixed_paths_count(g, 0, 1);

    std::vector<std::pair<int, int>> expected;
    for (int i = 0; i <= GRAPH_SIZE - 2; i++)
        expected.push_back({i, GRAPH_SIZE - 2 - i});

    REQUIRE(res.size() == expected.size());
    REQUIRE(std::equal(res.begin(), res.end(), expected.begin()));
}
