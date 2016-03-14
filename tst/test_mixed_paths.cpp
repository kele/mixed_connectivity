#include "catch.hpp"

#include "mixed_paths.hpp"
#include "extraordinary_graphs.hpp"

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


// TODO: unhide this test after mixed_paths work correctly
TEST_CASE("Mixed path's for Petersen's graph", "[mixed_paths][.]")
{
    SimpleGraph g(10);
    for (const auto &e : petersen_graph_e)
    {
        g.add_edge(e);
    }

    // TODO: fix mixed paths, because apparently, it does not work
    auto mixed_paths_count = get_mixed_paths_count(g, 0, 4);
}
