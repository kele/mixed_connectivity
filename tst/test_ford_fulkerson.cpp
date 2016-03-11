#include "catch.hpp"

#include "ford_fulkerson.hpp"
#include "estd.hpp"

TEST_CASE("Ford Fulkerson on a simple path", "[ford_fulkerson]")
{
    Graph<flow_edge_t> g(5);

    auto f = flow_edge_t::create(1, 2);
    f.flow(0);
    f.capacity(10);
    g.add_edge(f);
    g.add_edge(f.create_reverse());

    auto f2 = flow_edge_t::create(2, 3);
    f2.flow(0);
    f2.capacity(3);
    g.add_edge(f2);
    g.add_edge(f2.create_reverse());

    FordFulkerson::maxflow(estd::mut(g), 1, 3);

    int sum = 0;
    for (auto e : g.neighbours(1))
        sum += e.flow();

    REQUIRE(sum == 3);
    // TODO: test the flow on particular edges
}
