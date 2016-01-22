#pragma once
#include <memory>
#include "graph.hpp"

class MixedPathsCounter
{
public:
    using path_t = std::vector<edge_base_t>;

    MixedPathsCounter(std::shared_ptr<SimpleGraph> g, int paths_to_remove,
            int start, int stop);
    /* This function is *NOT* reentrant */
    void operator()(const path_t &path);
    int result() const;

private:
    std::shared_ptr<SimpleGraph> m_g;
    int m_paths_to_remove;
    int m_result;
    int m_start;
    int m_stop;
};
