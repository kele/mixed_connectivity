#include "path.hpp"
#include <vector>


using estd::mut;

namespace
{
    template<class G, class F>
    class ForAllPaths
    {
    public:
        ForAllPaths(G g, int start, int stop, F f)
            : m_g(g)
            , m_start(start)
            , m_stop(stop)
            , m_f(f)
            , m_visited(g.size())
        {
        }

        void exec()
        {
            multi_bfs(m_start);
        }

    private:
        G m_g;
        int m_start, m_stop;
        F m_f;
        path_t m_path;
        std::vector<bool> m_visited;

        void multi_bfs(int v)
        {
            m_visited[v] = true;
            m_path.push_back(v);
            if (v == m_stop)
            {
                m_f(m_path, m_g);
            }
            else
            {
                for (const auto &e : m_g.neighbours(v))
                {
                    const auto u = e.stop;
                    if (!m_visited[u])
                        multi_bfs(u);
                }
            }
            m_path.pop_back();
            m_visited[v] = false;
        }
    };
} // anonymous namespace

void for_all_paths(SimpleGraph g, int start, int stop, functor_t f)
{
    ForAllPaths<SimpleGraph, functor_t>(g, start, stop, f).exec();
}

void extract_path_edges(estd::mutref<SimpleGraph> g, const path_t &path)
{
    int v = path[0];

    for (int i = 1; i < path.size(); i++)
    {
        int u = path[i];
        g->remove_edge({v, u});

        v = u;
    }
}

void extract_path_vertices(estd::mutref<SimpleGraph> g, const path_t &path)
{
    for (const auto &v : path)
        g->remove_vertex(v);
}
