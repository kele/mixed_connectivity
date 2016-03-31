#include <fstream>
#include <iostream>
#include <sstream>
#include <functional>

#include "estd.hpp"
#include "load_graph.hpp"

void print_usage()
{
    std::cout << "TODO" << std::endl;
}

int process_main(int argc, char *argv[], std::function<void(const SimpleGraph &, int)> f)
{
    if (argc != 2)
    {
        print_usage();
        return -1;
    }

    const auto input_filename = argv[1];
    std::ifstream input(input_filename);
    std::string line;

    int line_num = 1;
    while (input.good())
    {
        if (line_num % 100 == 0)
            std::cerr << line_num << "... ";

        std::getline(input, line);
        if (line != "")
        {
            std::stringstream liness(line);
            auto g = load_graph(estd::mut(liness));
            f(g, line_num);
            line_num++;
        }
    }

    return 0;
}
