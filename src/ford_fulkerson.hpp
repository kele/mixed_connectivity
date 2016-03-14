#include <type_traits>

#include "flow.hpp"
#include "estd.hpp"

namespace FordFulkerson
{
    template<class Digraph>
    using IsFlowable = std::is_base_of<flow_edge_t, typename Digraph::edge_t>;
} // namespace FordFulkerson

namespace
{
    using namespace FordFulkerson;
    using namespace estd;

    template<class Digraph, typename = IsFlowable<Digraph>>
    struct state_t
    {
        explicit state_t(mutref<Digraph> g_) : g(g_) {}
        state_t() = delete;

        Digraph &g;
        std::vector<typename Digraph::edge_t*> path;
        std::vector<bool> visited;
    };

    template<class Digraph, typename = IsFlowable<Digraph>>
    int dfs(mutref<state_t<Digraph>> state, int s, int t)
    {
        state->visited[s] = true;

        if (s == t)
            return std::numeric_limits<int>::max();
        else
        {
            for (auto &e : state->g.neighbours(s))
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

    template<class Digraph, typename = IsFlowable<Digraph>>
    bool add_flow(mutref<state_t<Digraph>> state, int s, int t)
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
} // anonymous namespace

namespace FordFulkerson
{

    using namespace estd;

    template<class Digraph, typename = IsFlowable<Digraph>>
    void maxflow(mutref<Digraph> g, int s, int t)
    {
        using edge_t = typename Digraph::edge_t;

        state_t<Digraph> state(g);

        state.visited.resize(g->size());
        state.g.for_each_edge([](edge_t* e) { e->flow(0); });

        while (add_flow(mut(state), s, t))
            ;
    }

} // namespace FordFulkerson
