#pragma once
#include <memory>
#include <set>

#include "graph.hpp"

using path_t = std::vector<edge_base_t>;
using functor_t = std::function<void(const path_t &)>;

void for_all_paths(SimpleGraph *g, int start, int stop, const functor_t &f);
