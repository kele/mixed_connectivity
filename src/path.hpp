#pragma once
#include <memory>
#include <set>

#include "estd.hpp"
#include "graph.hpp"

using path_t = std::vector<int>;
using functor_t = std::function<void(const path_t &)>;

void for_all_paths(estd::mutref<SimpleGraph> g, int start, int stop, functor_t f);

void extract_path_edges(estd::mutref<SimpleGraph> g, const path_t &path);
void extract_path_vertices(estd::mutref<SimpleGraph> g, const path_t &path);
