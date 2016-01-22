#include <type_traits>

#include "flow.hpp"

namespace FordFulkerson
{

template<class Graph>
using IsFlowable = std::is_base_of<flow_edge_t, typename Graph::edge_t>;

template<class Graph, typename = IsFlowable<Graph>>
struct state_t
{
    explicit state_t(Graph *g_) : g(g_) {}
    state_t() = delete;

    Graph* g;
    std::vector<typename Graph::edge_t*> path;
    std::vector<bool> visited;
};

template<class Graph, typename = IsFlowable<Graph>>
int dfs(state_t<Graph>* state, int s, int t)
{
    state->visited[s] = true;

    if (s == t)
    {
        return std::numeric_limits<int>::max();
    }
    else
    {
        for (auto &e : state->g->neighbours(s))
        {
            if (!state->visited[e.stop] and e.cf() > 0)
            {
                int delta = std::min(e.cf(), dfs(state, e.stop, t));
                if (delta > 0)
                {
                    state->path.push_back(&e);
                    return delta;
                }
            }
        }
    }

    return 0;
}

template<class Graph, typename = IsFlowable<Graph>>
bool add_flow(state_t<Graph>* state, int s, int t)
{
    std::fill(state->visited.begin(), state->visited.end(), false);
    state->path.clear();

    int delta = dfs(state, s, t);
    if (delta > 0)
    {
        for (auto e : state->path)
        {
            e->flow(e->flow() + delta);
        }
        return true;
    }
    return false;
}

template<class Graph, typename = IsFlowable<Graph>>
void maxflow(Graph *g, int s, int t)
{
    using edge_t = typename Graph::edge_t;

    state_t<Graph> state(g);

    state.visited.resize(g->size());
    state.g->for_each_edge([](edge_t* e) { e->flow(0); });

    while (add_flow(&state, s, t))
        ;
}

} // namespace FordFulkerson
