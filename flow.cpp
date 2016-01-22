#include "flow.hpp"

struct flow_edge_t::flow_edge_shared_t
{
    int flow;
};

flow_edge_t::flow_edge_t(const edge_base_t &e)
    : edge_base_t(e)
{}


flow_edge_t flow_edge_t::create_reverse() const
{
    flow_edge_t r(edge_base_t{stop, start});
    r.m_shared = m_shared;
    r.m_is_reverse = true;
    r.m_capacity = m_capacity;
    return r;
}

/* static */ flow_edge_t flow_edge_t::create(int start, int stop)
{
    flow_edge_t f(edge_base_t{start, stop});
    f.m_is_reverse = false;
    f.m_shared = std::make_shared<flow_edge_shared_t>();
    f.m_shared->flow = 0;
    f.m_capacity = 0;
    return f;
}

int flow_edge_t::flow() const
{
    return m_is_reverse ? - m_shared->flow : m_shared->flow;
}

void flow_edge_t::flow(int f)
{
    if (m_is_reverse)
        m_shared->flow = -f;
    else
        m_shared->flow = f;
}

int flow_edge_t::capacity() const
{
    return m_capacity;
}

void flow_edge_t::capacity(int c)
{
    m_capacity = c;
}

int flow_edge_t::cf() const
{
    return m_capacity - flow();
}
