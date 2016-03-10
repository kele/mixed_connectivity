#include "load_graph.hpp"

#include <cstring>
#include <sstream>

#include "estd.hpp"

namespace
{
const int SIZE_DELIM = -1;
const int NEIGH_DELIM = -2;
const int GRAPH_DELIM = -3;
} // anonymous namespace


struct vertex_list
{
    std::vector<int> neighbours;
};


SimpleGraph load_graph(std::istream &&s)
{
    int graph_size;
    s >> graph_size;

    int next;
    s >> next;
    estd::throw_assert(next == SIZE_DELIM);

    SimpleGraph g(graph_size);

    int v = 0;
    while (s >> next, next != GRAPH_DELIM)
    {
        if (next == NEIGH_DELIM)
        {
            v++; continue;
        }

        g.add_edge({v, next});
    }

    return g;
}

