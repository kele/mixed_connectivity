#pragma once

#include <vector>
#include <utility>

#include "graph.hpp"

std::vector<std::pair<int, int>> get_mixed_paths_count(
    const SimpleGraph &g, int start, int stop);
