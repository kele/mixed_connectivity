#pragma once
#include <limits>
#include <memory>

#include "graph.hpp"
#include "utils.hpp"

class flow_edge_t : public edge_base_t
{
    struct flow_edge_shared_t
    {
        int flow;
    };

public:
    flow_edge_t(const flow_edge_t &) = default;

    explicit flow_edge_t(const edge_base_t &e)
        : edge_base_t(e)
    {}

    flow_edge_t create_reverse() const
    {
        flow_edge_t r(edge_base_t{stop, start});
        r.m_shared = m_shared;
        r.m_is_reverse = true;
        r.m_capacity = m_capacity;
        return std::move(r);
    }

    template<class... Args>
    static flow_edge_t create(int start, int stop)
    {
        flow_edge_t f(edge_base_t{start, stop});
        f.m_is_reverse = false;
        f.m_shared = std::make_shared<flow_edge_shared_t>();
        f.m_shared->flow = 0;
        f.m_capacity = 0;
        return std::move(f);
    }

    int flow() const
    {
        return m_is_reverse ? - m_shared->flow : m_shared->flow;
    }

    void flow(int f)
    {
        if (m_is_reverse)
            m_shared->flow = -f;
        else
            m_shared->flow = f;
    }

    int capacity() const
    {
        return m_capacity;
    }

    void capacity(int c)
    {
        m_capacity = c;
    }

    int cf() const
    {
        return m_capacity - flow();
    }

private:
    int m_capacity;
    bool m_is_reverse;
    std::shared_ptr<flow_edge_shared_t> m_shared;
};

template<
    class Graph,
    typename = std::is_base_of<flow_edge_t, typename Graph::edge_t>
>
class FordFulkerson
{
public:
    using edge_t = typename Graph::edge_t;

    void ford_fulkerson(Graph *g, int s, int t)
    {
        visited.resize(g->size());

        g->for_each_edge([](edge_t* e) { e->flow(0); });

        while (add_flow(g, s, t))
            ;
    }

private:
    std::vector<edge_t*> path;
    std::vector<bool> visited;

    int dfs(Graph *g, int s, int t)
    {
        visited[s] = true;

        if (s == t)
        {
            return std::numeric_limits<int>::max();
        }
        else
        {
            for (auto &e : g->neighbours(s))
            {
                if (!visited[e.stop] and e.cf() > 0)
                {
                    int delta = std::min(e.cf(), dfs(g, e.stop, t));
                    if (delta > 0)
                    {
                        path.push_back(&e);
                        return delta;
                    }
                }
            }
        }

        return 0;
    }


    bool add_flow(Graph *g, int s, int t)
    {
        unvisit_all();
        path.clear();

        int delta = dfs(g, s, t);
        if (delta > 0)
        {
            for (auto e : path)
            {
                e->flow(e->flow() + delta);
            }
            return true;
        }
        return false;
    }

    void unvisit_all()
    {
        std::fill(visited.begin(), visited.end(), false);
    }
};

