#include "subsets.hpp"
#include <iostream>

int main()
{
    std::vector<int> t = {1, 2, 3, 4};

    SubsetGenerator<int> g;
    g.init(t, 2);

    do
    {
        for (auto x : g.get())
            std::cout << x << " ";
        std::cout << "\n";
    } while (g.next());
}
