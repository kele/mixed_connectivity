#include "edge_connectivity.hpp"
#include "ford_fulkerson.hpp"
#include "graph.hpp"
#include "estd.hpp"

int get_edge_connectivity(int start, int stop, SimpleGraph g)
{
    Digraph<flow_edge_t> dg(g.size());
    for (const auto &e : g.edges())
    {
        auto f = flow_edge_t::create(e.start, e.stop);
        f.flow(0); // This is shared between f and fr
        auto fr = f.create_reverse();

        f.capacity(1);
        fr.capacity(1);

        dg.add_edge(f);
        dg.add_edge(fr);
    }

    FordFulkerson::maxflow(estd::mut(dg), start, stop);

    int sum = 0;
    for (const auto &e : dg.neighbours(start))
        sum += e.flow();
    return sum;
}
