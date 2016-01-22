#include "ford_fulkerson.hpp"
#include <iostream>

int main()
{
    auto f = flow_edge_t::create(1, 2);
    f.flow(0);
    f.capacity(10);
    auto fr = f.create_reverse();

    std::cout << "1 -> 2 (f = " << f.flow() << ", c = " << f.capacity() << ", cf = " << f.cf() << ")" << std::endl;
    std::cout << "2 -> 1 (f = " << fr.flow() << ", c = " << fr.capacity() << ", cf = " << fr.cf() << ")" << std::endl;

    f.capacity(10);

    std::cout << "1 -> 2 (f = " << f.flow() << ", c = " << f.capacity() << ", cf = " << f.cf() << ")" << std::endl;
    std::cout << "2 -> 1 (f = " << fr.flow() << ", c = " << fr.capacity() << ", cf = " << fr.cf() << ")" << std::endl;


    Graph<flow_edge_t> g(5);
    g.add_edge(f);
    g.add_edge(fr);

    auto f2 = flow_edge_t::create(2, 3);
    f2.flow(0);
    f2.capacity(3);
    auto fr2 = f2.create_reverse();

    g.add_edge(f2);
    g.add_edge(fr2);

    FordFulkerson::maxflow(&g, 1, 3);

    int sum = 0;
    for (auto e : g.neighbours(1))
    {
        sum += e.flow();
    }
    std::cout << "Flow: " << sum << std::endl;

    g.for_each_edge([](edge_base_t *e) {
            auto fe = static_cast<flow_edge_t*>(e);
            std::cout << *e << "(f = " << fe->flow() << ")" << std::endl;
            });
}
