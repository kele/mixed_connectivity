#include "graph.hpp"



bool is_path(const Graph &g, const std::vector<int> &path)
{
    auto current = path.first();

    for (size_t i = 1; i < path.size(); i++)
    {
        if (g.neighbours(current).count(path[i]) == 0)
            return false;

        current = path[i];
    }
    return true;
}
