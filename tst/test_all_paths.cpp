#include <iostream>
#include <functional>

#include "graph.hpp"
#include "path.hpp"

void print_path(const std::vector<edge_base_t> &path)
{
    for (const auto &e : path)
        std::cout << "(" << e.start << ", " << e.stop << ") ";
    std::cout << std::endl;
}

int main()
{
    auto g = std::make_shared<SimpleGraph>(4);

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            g->add_edge({i, j});

    /* 1 -> 2 -> 3 -> 4 */
    /* 1 -> 2 -> 4 */
    /* 1 -> 3 - > 4 */
    /* 1 -> 4 */

    for_all_paths(g.get(), 0, 3, print_path);
}
