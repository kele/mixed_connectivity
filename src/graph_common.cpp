#include "graph_common.hpp"

#include <stdexcept>

edge_base_t::edge_base_t(const std::initializer_list<int> &e)
{
    if (e.size() != 2)
        throw std::logic_error("edge_base_t needs exactly two arguments.");

    auto it = e.begin();
    start = *it;
    ++it;
    stop = *it;;
}

bool operator==(const edge_base_t &lhs, const edge_base_t &rhs)
{
    return lhs.start == rhs.start and lhs.stop == rhs.stop;
}

std::ostream& operator<<(std::ostream &os, const edge_base_t &e)
{
    os << e.start << " -> " << e.stop;
    return os;
}
