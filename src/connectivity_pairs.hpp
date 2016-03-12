#pragma once

#include "graph.hpp"

std::vector<std::pair<int, int>> get_connectivity_pairs(
        const SimpleGraph &g, int start, int stop);
