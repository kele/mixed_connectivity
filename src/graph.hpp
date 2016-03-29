#pragma once

#include "graph_common.hpp"

#include <vector>
#include <functional>
#include <algorithm>
#include <sstream>

template<
    class Edge = edge_base_t,
    typename = std::is_base_of<edge_base_t, Edge>
>
class Graph
{
public:
    using edge_t = Edge;

    explicit Graph(size_t n)
        : E(n)
        , num_of_edges_(0)
    {
    }

    size_t size() const
    {
        return E.size();
    }

    void remove_vertex(int v)
    {
        num_of_edges_ -= E[v].size();
        E[v].clear();

        for (int i = 0; i < size(); i++)
        {
            auto it = std::remove_if(E[i].begin(), E[i].end(), [v](const edge_t &e) { return e.stop == v; });
            E[i].erase(it, E[i].end());
        }
    }

    std::vector<edge_t> edges() const
    {
        std::vector<edge_t> result;
        for_each_edge([&result] (const edge_t *e) { result.push_back(*e); });
        return result;
    }

    void for_each_edge(std::function<void(edge_t*)> f)
    {
        for (auto &edges_ : E)
            for (auto &e : edges_)
                if (e.start < e.stop)
                    f(&e);
    }
    void for_each_edge(std::function<void(const edge_t*)> f) const
    {
        for (auto &edges_ : E)
            for (auto &e : edges_)
                if (e.start < e.stop)
                    f(&e);
    }

    void add_edge(edge_t e)
    {
        E[e.start].push_back(e);
        E[e.stop].emplace_back(reverse(e));
        num_of_edges_++;
    }

    void remove_edge(edge_base_t e)
    {
        remove_edge(e.start, e.stop);
    }
    void remove_edge(int u, int v)
    {
        remove_uni_edge(u, v);
        remove_uni_edge(v, u);
        num_of_edges_--;
    }

    size_t num_of_edges() const
    {
        return num_of_edges_;
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

    void remove_uni_edge(int u, int v)
    {
        auto it = find_edge(u, v);
        if (it == E[u].end())
        {
            std::stringstream ss;
            ss << "Edge (" << u << ", " << v << ") does not exist.";
            throw std::out_of_range(ss.str());
        }
        *it = E[u].back();
        E[u].pop_back();
    }

    auto find_edge(int u, int v) -> decltype(E[u].begin())
    {
        return std::find_if(E[u].begin(), E[u].end(), [v](const edge_base_t &e) { return e.stop == v; });
    }
};

using SimpleGraph = Graph<>;
