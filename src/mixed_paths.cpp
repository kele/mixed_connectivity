#include "mixed_paths.hpp"

#include <algorithm>
#include <map>

#include "path.hpp"
#include "estd.hpp"
#include "edge_connectivity.hpp"

#include <iostream>

using namespace estd;

namespace
{
    // TODO:
    // - think about getting rid of these internal state m_k, m_wip_k, m_g_paths_extracted and so on.
    class MixedPaths
    {
    public:
        MixedPaths(SimpleGraph g)
            : m_g_paths_extracted(g)
        {
            m_f = [this](const path_t &p, const SimpleGraph &g_) { extract_path_and_continue(p, g_); };
        }

        std::vector<std::pair<int, int>> get(int start, int stop)
        {
            /* Idea of the algorithm:
             * 1. Find a path.
             * 2. Remove the inner vertices of this path.
             * 3. Recurse.
             * 4. After reaching k-levels of recursion, restore the original graph.
             * 5. Remove all these (edge) paths from the graph.
             * 6. Compute edge connectivity.
             * 7. The biggest result of 6 is the final result.
             */

            m_start = start;
            m_stop = stop;

            std::vector<std::pair<int, int>> res;
            for (int k = 0; k <= m_g_paths_extracted.size() - 2; k++)
            {
                m_wip_k = 0;
                m_k = k;
                for_all_paths(m_g_paths_extracted, m_start, m_stop, m_f);

                res.push_back({k, m_cp[k]});
            }
            return res;
        }

    private:
        int m_k, m_wip_k;
        SimpleGraph m_g_paths_extracted;
        functor_t m_f;
        int m_start, m_stop;
        std::map<int, int> m_cp;

        void extract_path_and_continue(const path_t &path, SimpleGraph g)
        {
            auto saved_g = m_g_paths_extracted;

            // Check edge connectivity without paths deleted before this call
            int edge_con = get_edge_connectivity(m_start, m_stop, m_g_paths_extracted);

            //std::cerr << "Graph: " << std::endl;
            //m_g_paths_extracted.for_each_edge([](const edge_base_t *e) { std::cerr << *e << "\n"; });
            //std::cerr << "Edge conn (" << m_start << " -> " << m_stop << "): " << edge_con << "\n\n";

            m_cp[m_wip_k] = std::max(m_cp[m_wip_k], edge_con);

            // Recurse (find a new path to extract)
            if (m_wip_k < m_k)
            {
                extract_path_edges(mut(m_g_paths_extracted), path);

                for (int i = 1; i < path.size() - 1; i++)
                    g.remove_vertex(path[i]);
                m_wip_k++;

                for_all_paths(g, m_start, m_stop, m_f);

                m_wip_k--;
            }

            m_g_paths_extracted = saved_g;
        }
    };
} // anonymous namespace

std::vector<std::pair<int, int>> get_mixed_paths_count(
    const SimpleGraph &g, int start, int stop)
{
    return MixedPaths(g).get(start, stop);
}
