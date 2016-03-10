#include <iostream>
#include <functional>

#include "graph.hpp"
#include "path.hpp"
#include "estd.hpp"

void print_path(const std::vector<int> &path)
{
    for (const auto &v : path)
        std::cout << v << " ";
    std::cout << std::endl;
}

int main()
{
    SimpleGraph g(4);

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            g.add_edge({i, j});

    /* 1 -> 2 -> 3 -> 4 */
    /* 1 -> 2 -> 4 */
    /* 1 -> 3 - > 4 */
    /* 1 -> 4 */

    for_all_paths(estd::mut(g), 0, 3, print_path);
}
