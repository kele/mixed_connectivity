#pragma once

#include <istream>

#include "graph.hpp"

SimpleGraph load_graph(std::istream &&s);
