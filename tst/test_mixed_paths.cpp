#include "mixed_paths.hpp"

#include "estd.hpp"

using estd::throw_assert;

int main()
{
    SimpleGraph g(6);

    // Cykl z dwoma cieciwami (translate)
    for (int i = 0; i < 6; i++)
    {
        g.add_edge({i, (i + 1) % 6});
        g.add_edge({(i + 1) % 6, i});
    }
    g.add_edge({0, 2});
    g.add_edge({2, 0});

    g.add_edge({3, 1});
    g.add_edge({1, 3});

    auto res = get_mixed_paths_count(g, 0, 3);
    std::vector<std::pair<int, int>> expected =
    {
        {0, 3}, {1, 2}, {2, 1}, {3, 0}, {4, 0}
    };

    throw_assert(res.size() == expected.size());
    throw_assert(std::equal(res.begin(), res.end(), expected.begin()));
}
