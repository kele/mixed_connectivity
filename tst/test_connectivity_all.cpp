#include <iostream>
#include <algorithm>

#include "edge_connectivity.hpp"
#include "graph.hpp"
#include "subsets.hpp"

int main()
{
    int size = 4;

    std::vector<edge_base_t> all_edges;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            all_edges.push_back(edge_base_t{i, j});

    int count = 0;
    for (int i = 1; i <= all_edges.size(); i++)
    {
        SubsetGenerator<edge_base_t> s;
        s.init(all_edges, i);

        do
        {
            auto edges = s.get();

            int connected = size;
            for (int i = 0; i < size; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    int c = get_edge_connectivity(i, j, size, edges);
                    connected = std::min(connected, c);
                }
            }
            
/*
            std::cout << "This graph is " << connected << " connected." << std::endl;
            for (const auto &e : edges)
                std::cout << "(" << e.start << ", " << e.stop << ") ";
            std::cout << "---\n\n";
*/

            count++;

            if (count % 10000 == 0)
                std::cout << count << " considered" << std::endl;
        } while (s.next());
    }

    std::cout << "Considered " << count << " graphs!\n";
    return 0;
}
