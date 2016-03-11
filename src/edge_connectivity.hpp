#pragma once
#include <vector>

#include "graph.hpp"

struct edge_base_t;

int get_edge_connectivity(int start, int stop, int size, const std::vector<edge_base_t>& edges);
int get_edge_connectivity(int start, int stop, SimpleGraph g, bool directed);
