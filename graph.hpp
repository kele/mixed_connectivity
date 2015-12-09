#include <vector>
#include <set>
#include <ostream>
#include <cstdint>
#include <stdexcept>


class Graph
{
public:
    Graph(size_t n)
        : E(n)
    {
    }

    size_t size() const
    {
        return E.size();
    }

    void add_edge(int u, int v)
    {
        E[u].insert(v);
    }

    void remove_edge(int u, int v)
    {
        auto it = E[u].find(v);
        if (it == E[u].end())
            throw std::out_of_range("Edge does not exist.");

        E[u].erase(it);
    }

    const std::multiset<int> & neighbours(int u) const
    {
        return E[u];
    }

private:
    void print(std::ostream &os) const
    {
        for (unsigned i = 0; i < size(); i++)
            for (auto n : neighbours(i))
                os << i << " -> " << n << std::endl;
    }

    friend std::ostream& operator<<(std::ostream &os, const Graph& g)
    {
        g.print(os);
        return os;
    }

    std::vector<std::multiset<int>> E;
};

