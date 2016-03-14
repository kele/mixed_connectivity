#pragma once

#include <istream>

#include "graph.hpp"
#include "estd.hpp"

SimpleGraph load_graph(estd::mutref<std::istream> s);
