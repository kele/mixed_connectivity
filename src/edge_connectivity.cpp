#include "edge_connectivity.hpp"
#include "ford_fulkerson.hpp"
#include "graph.hpp"
#include "estd.hpp"

int get_edge_connectivity(int start, int stop, int size, const std::vector<edge_base_t>& edges)
{
    Graph<flow_edge_t> g(size);

    for (const auto &e : edges)
    {
        auto f = flow_edge_t::create(e.start, e.stop);
        f.flow(0); // This is shared between f and fr
        auto fr = f.create_reverse();

        f.capacity(1);
        fr.capacity(1);

        g.add_edge(f);
        g.add_edge(fr);
    }

    FordFulkerson::maxflow(estd::mut(g), start, stop);

    int sum = 0;
    for (const auto &e : g.neighbours(start))
        sum += e.flow();

    return sum;
}

int get_edge_connectivity(int start, int stop, SimpleGraph g)
{
    std::vector<edge_base_t> es;

    const auto &edges = g.edges();
    std::transform(edges.begin(), edges.end(), std::back_inserter(es),
            [](const SimpleGraph::edge_t &e) { return edge_base_t(e); });

    return get_edge_connectivity(start, stop, g.size(), es);
}
