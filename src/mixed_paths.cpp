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

    for (const auto &e : path)
    {
        new_g->remove_vertex(e.start);
        new_g->remove_vertex(e.stop);
    }


    std::cout << "Removing path...\n";
    for (const auto &e : path)
        std::cout << "(" << e.start << ", " << e.stop << ") ";
    std::cout << std::endl;

    m_paths_to_remove--;

    if (m_paths_to_remove == 0)
    {
        int edge_connectivity = get_edge_connectivity(
                m_start, m_stop, new_g->size(), new_g->edges());
        std::cout << "edge connectivity (" << m_start << ", " << m_stop << ") = "
            << edge_connectivity << std::endl;
        m_result = std::min(m_result, edge_connectivity);
    }
    else
    {
        for_all_paths(new_g.get(), m_start, m_stop, *this);
    }
    m_paths_to_remove++;
}
