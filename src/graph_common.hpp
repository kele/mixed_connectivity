#pragma once

#include <ostream>


struct edge_base_t
{
    edge_base_t(const std::initializer_list<int> &e);
    int start, stop;
};

inline edge_base_t reverse(const edge_base_t &e)
{
    return {e.stop, e.start};
}

bool operator==(const edge_base_t &lhs, const edge_base_t &rhs);
std::ostream& operator<<(std::ostream &os, const edge_base_t &e);

