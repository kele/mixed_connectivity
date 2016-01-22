#include <iostream>

#include "mixed_paths.hpp"
#include "path.hpp"


int main()
{
    auto g = std::make_shared<SimpleGraph>(5);

    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            g->add_edge({i, j});

    for (int i = 1; i < 5; i++)
    {
        MixedPathsCounter counter(g, i, 0, 4);

        for_all_paths(g.get(), 0, 4, [&counter](const MixedPathsCounter::path_t& p){ counter(p); });

        std::cout << "Edge connectivity for k = " << i << " is " << counter.result();
        std::cout << std::endl;
    }
}
