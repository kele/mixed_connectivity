#include "path.hpp"

/* TODO: rewrite it completely! don't use this internal lambda */
void for_all_paths(SimpleGraph *g, int start, int stop, functor_t f)
{
    path_t path;
    std::set<int> visited; // TODO: change it to a vector

    std::function<void(int, int)> multi_bfs =
    [g, &f, &path, &visited, &multi_bfs]
    (int start_, int stop_)
    {
        visited.insert(start_);

        if (start_ == stop_)
            f(path);

        for (const auto &e : g->neighbours(start_))
        {
            int next = e.stop;
            if (visited.count(next) == 0)
            {
                path.push_back({start_, next});
                multi_bfs(next, stop_);
                path.pop_back();
            }
        }

        visited.erase(start_);
    };

    multi_bfs(start, stop);
}
