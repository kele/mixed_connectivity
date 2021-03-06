#pragma once
#include "graph_common.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <type_traits>
#include <vector>


template<
    class Edge = edge_base_t,
    typename = std::is_base_of<edge_base_t, Edge>
>
class Digraph
{
public:
    using edge_t = Edge;

    Digraph(size_t n)
        : E(n)
        , num_of_edges_(0)
    {
    }

    void remove_vertex(int v)
    {
        num_of_edges_ -= E[v].size();
        E[v].clear();

        for (int i = 0; i < size(); i++)
        {
            auto it = std::remove_if(E[i].begin(), E[i].end(), [v](const edge_t &e) { return e.stop == v; });

            num_of_edges_ -= std::distance(it, E[i].end());
            E[i].erase(it, E[i].end());
        }
    }

    void for_each_edge(std::function<void(edge_t*)> f)
    {
        for (auto &edges_ : E)
            for (auto &e : edges_)
                f(&e);
    }

    void for_each_edge(std::function<void(const edge_t*)> f) const
    {
        for (auto &edges_ : E)
            for (auto &e : edges_)
                f(&e);
    }

    std::vector<edge_t> edges() const
    {
        std::vector<edge_t> result;
        for_each_edge([&result] (const edge_t *e) { result.push_back(*e); });
        return result;
    }

    size_t size() const
    {
        return E.size();
    }

    size_t num_of_edges() const
    {
        return num_of_edges_;
    }

    void add_edge(edge_t e)
    {
        E[e.start].push_back(e);
        num_of_edges_++;
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

        num_of_edges_--;
    }

    // TODO:
    // - change this to incident_edges.
    // - add a real neighbours() method
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

    size_t num_of_edges_;

    void print(std::ostream &os) const
    {
        for (unsigned i = 0; i < size(); i++)
            for (auto e : neighbours(i))
                os << e << std::endl;
    }

    friend std::ostream& operator<<(std::ostream &os, const Digraph& g)
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

using SimpleDigraph = Digraph<>;
