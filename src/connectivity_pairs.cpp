#include "connectivity_pairs.hpp"
#include "subsets.hpp"
#include "estd.hpp"
#include "path.hpp"

using estd::mutref;
using estd::mut;

bool start_smaller(const edge_base_t &e)
{
    return e.start < e.stop;
}

void filter_edges(mutref<std::vector<SimpleGraph::edge_t>> v)
{
    v->erase(std::remove_if(v->begin(), v->end(), start_smaller), v->end());
}

// TODO: change that to an undirected graph
std::vector<std::pair<int, int>> get_connectivity_pairs(
        const SimpleGraph &g, int start, int stop)
{
    using namespace std;

    vector<pair<int, int>> res;

    vector<int> vertices;
    for (int i = 0; i < g.size(); i++)
        if (i != start and i != stop)
            vertices.push_back(i);

    SubsetGenerator<SimpleGraph::edge_t> edges_subset;
    SubsetGenerator<int> vertices_subset;


    for (int k_vertices = 0; k_vertices < g.size() - 1; k_vertices++)
    {
        size_t best_l_edges = g.num_of_edges();

        for (size_t l_edges = 0; l_edges < best_l_edges; l_edges++)
        {
            vertices_subset.init(vertices, k_vertices);

            do {
                auto g_vertices_removed = g;

                for (const auto &v : vertices_subset.get())
                    g_vertices_removed.remove_vertex(v);

                auto edges = g_vertices_removed.edges();

                if (edges.size() <= l_edges)
                {
                    // Removing these vertices will make the graph empty.
                    best_l_edges = min(best_l_edges, edges.size());
                    break;
                }

                edges_subset.init(edges, l_edges);

                auto g_copy = g_vertices_removed;
                do {
                    g_vertices_removed = g_copy;
                    for (const auto &e : edges_subset.get())
                        g_vertices_removed.remove_edge(e);

                    if (!are_connected(g_vertices_removed, start, stop))
                    {
                        best_l_edges = min(best_l_edges, l_edges);
                        break;
                    }
                } while (edges_subset.next());
            } while (vertices_subset.next());
        }

        res.emplace_back(k_vertices, best_l_edges);
    }

    return res;
}
