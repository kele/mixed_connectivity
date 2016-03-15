#pragma once

#include <ostream>
#include <vector>

#include "graph.hpp"
#include "estd.hpp"

void print_dot(estd::mutref<std::ostream> os, const std::string &graphname,
        const SimpleGraph &g, const std::vector<int> &marked);
