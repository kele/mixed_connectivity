#pragma once
#include <functional>
#include "graph.hpp"

int process_main(int argc, char *argv[], std::function<void(const SimpleGraph &, int)> f);
