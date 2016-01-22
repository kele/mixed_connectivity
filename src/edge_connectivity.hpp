#pragma once
#include <vector>

struct edge_base_t;

int get_edge_connectivity(int start, int stop, int size, const std::vector<edge_base_t>& edges);
