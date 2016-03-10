#include "path.hpp"
#include <vector>


using estd::mut;

namespace
{
    class ForAllPaths
    {
    public:
        ForAllPaths(estd::mutref<SimpleGraph> g, int start, int stop, functor_t f)
            : m_g(g)
            , m_start(start)
            , m_stop(stop)
            , m_f(f)
            , m_visited(g->size())
        {
        }

        void exec()
        {
            multi_bfs(m_start);
        }

    private:
        estd::mutref<SimpleGraph> m_g;
        int m_start, m_stop;
        functor_t m_f;
        path_t m_path;
        std::vector<bool> m_visited;

        void multi_bfs(int v)
        {
            m_visited[v] = true;
            m_path.push_back(v);
            if (v == m_stop)
            {
                m_f(m_path);
            }
            else
            {
                for (const auto &e : m_g->neighbours(v))
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

void for_all_paths(estd::mutref<SimpleGraph> g, int start, int stop, functor_t f)
{
    ForAllPaths falp(g, start, stop, f);
    falp.exec();
}
