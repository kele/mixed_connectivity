#include <limits>
#include "mixed_paths.hpp"
#include "edge_connectivity.hpp"
#include "path.hpp"

#include <iostream> // DEBUG

MixedPathsCounter::MixedPathsCounter(
        std::shared_ptr<SimpleGraph> g,
        int paths_to_remove,
        int start,
        int stop)
    : m_g(g)
    , m_paths_to_remove(paths_to_remove)
    , m_result(std::numeric_limits<int>::max())
    , m_start(start)
    , m_stop(stop)
{}

int MixedPathsCounter::result() const
{
    return m_result;
}

void MixedPathsCounter::operator()(const path_t &path)
{
    auto new_g = std::make_shared<SimpleGraph>(*m_g);

    std::cout << "Removing path...\n";
    for (const auto &e : path)
        std::cout << "(" << e.start << ", " << e.stop << ") ";
    std::cout << std::endl;

    for (const auto &e : path)
    {
        for (auto v : {e.start, e.stop})
        {
            if (v != m_start and v != m_stop)
                new_g->remove_vertex(v);
        }
    }

    m_paths_to_remove--;
    std::cout << m_paths_to_remove << " paths to remove left!" << std::endl;

    if (m_paths_to_remove == 0)
    {
        int edge_connectivity = get_edge_connectivity(
                m_start, m_stop, new_g->size(), new_g->edges());
        std::cout << "edge connectivity (" << m_start << ", " << m_stop << ") = "
            << edge_connectivity << std::endl;
        std::cout << "Graph:\n" << *new_g << std::endl;
        m_result = std::min(m_result, edge_connectivity);
    }
    else
    {
        auto me = [this](const path_t &p) { this->operator()(p); };
        for_all_paths(new_g.get(), m_start, m_stop, me);
    }
    m_paths_to_remove++;
}
