#pragma once
// TODO: move implementation to impl header
#include <type_traits>
#include <functional>
#include <vector>
#include <ostream>
#include <cstdint>
#include <stdexcept>
#include <algorithm>


struct edge_base_t
{
    int start, stop;

    edge_base_t(const std::initializer_list<int> &e)
    {
        if (e.size() != 2)
            throw std::logic_error("edge_base_t needs exactly two arguments.");

        auto it = e.begin();
        start = *it;
        ++it;
        stop = *it;;
    }
};

inline std::ostream& operator<<(std::ostream &os, const edge_base_t &e)
{
    os << e.start << " --> " << e.stop;
    return os;
}

/* TODO: what about the container type for edges? */
template<
    class Edge = edge_base_t,
    typename = std::is_base_of<edge_base_t, Edge>
>
class Graph
{
public:
    using edge_t = Edge;

    Graph(size_t n)
        : E(n)
    {
    }

    void remove_vertex(int v)
    {
        E[v].clear();

        for (int i = 0; i < size(); i++)
        {
            auto it = std::remove_if(E[i].begin(), E[i].end(), [v](const edge_t &e) { return e.stop == v; });
            E[i].erase(it, E[i].end());
        }
    }

    void for_each_edge(std::function<void(edge_t*)> f)
    {
        for (auto &edges_ : E)
            for (auto &e : edges_)
                f(&e);
    }

    std::vector<edge_t> edges()
    {
        std::vector<edge_t> result;
        for_each_edge([&result] (edge_t *e) { result.push_back(*e); });
        return result;
    }

    size_t size() const
    {
        return E.size();
    }

    void add_edge(edge_t e)
    {
        E[e.start].push_back(e);
    }


    void remove_edge(edge_base_t e)
    {
        remove_edge(e.start, e.stop);
    }

    void remove_edge(int u, int v)
    {
        auto it = find_edge(u, v);
        if (it == E[u].end())
            throw std::out_of_range("Edge does not exist.");

        E[u].erase(it);
    }

    const std::vector<edge_t> & neighbours(int u) const
    {
        return E[u];
    }

    std::vector<edge_t> & neighbours(int u)
    {
        return E[u];
    }

private:
    std::vector<std::vector<edge_t>> E;

    void print(std::ostream &os) const
    {
        for (unsigned i = 0; i < size(); i++)
            for (auto e : neighbours(i))
                os << e << std::endl;
    }

    friend std::ostream& operator<<(std::ostream &os, const Graph& g)
    {
        g.print(os);
        return os;
    }

    auto find_edge(int u, int v) -> decltype(E[u].begin())
    {
        for (auto it = E[u].begin(); it != E[u].end(); ++it)
            if (it->stop == v)
                return it;
        return E[u].end();
    }
};

using SimpleGraph = Graph<>;
