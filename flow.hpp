#pragma once
#include <limits>
#include <memory>

#include "graph.hpp"
#include "utils.hpp"

/* Helper structure for maxflow algorithms */
class flow_edge_t : public edge_base_t
{
    struct flow_edge_shared_t;

public:
    flow_edge_t(const flow_edge_t &) = default;

    flow_edge_t create_reverse() const;
    static flow_edge_t create(int start, int stop);
    int flow() const;
    void flow(int f);
    int capacity() const;
    void capacity(int c);
    int cf() const;

private:
    explicit flow_edge_t(const edge_base_t &e);

    int m_capacity;
    bool m_is_reverse;
    std::shared_ptr<flow_edge_shared_t> m_shared;
};
