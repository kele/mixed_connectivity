#include "graph.hpp"
#include <iostream>

int main()
{
    Graph g(10);

    g.add_edge(1, 2);
    g.add_edge(1, 2);
    std::cout << "graph\n" << g << std::endl;

    g.remove_edge(1, 2);
    std::cout << "graph\n" << g << std::endl;

    g.add_edge(2, 1);
    g.add_edge(2, 5);
    std::cout << "graph\n" << g << std::endl;

}
