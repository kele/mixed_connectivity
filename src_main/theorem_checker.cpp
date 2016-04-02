#include <iostream>
#include <fstream>

#include "load_graph.hpp"
#include "connectivity_pairs.hpp"
#include "mixed_paths.hpp"

const int ARGS_NUM = 3;

void print_usage()
{
    std::cout << "theorem_checker [infile] [graphs_file]" << std::endl;
    std::cout << "WARNING! It is assumed that [infile] is sorted." << std::endl;
}

std::ostream& operator<<(std::ostream &os, const std::vector<std::pair<int, int>> &v)
{
    for (auto p : v)
        os << "(" << p.first << ", " << p.second << ") ";

    return os;
}

// Line format:
// [graph_number] [start] [stop]
int main(int argc, char *argv[])
{
    if (argc != ARGS_NUM)
    {
        print_usage();
        return 1;
    }

    const auto input_filename = argv[1];
    const auto graphs_filename = argv[2];

    std::ifstream input(input_filename);
    std::ifstream graphs_input(graphs_filename);
    std::string line;
    std::string graph_line;

    int graph_read_num = 0;
    int count = 0;
    int prev_graph_number = -1000;
    while (input.good())
    {
        std::getline(input, line);

        if (line != "")
        {
            int graph_number, start, stop;
            std::stringstream line_stream(line);
            line_stream >> graph_number >> start >> stop;

            if (graph_number > prev_graph_number + 1000)
            {
                prev_graph_number = graph_number;
                std::cerr << graph_number << std::endl;
            }

            while (graph_read_num < graph_number)
            {
                std::getline(graphs_input, graph_line);
                graph_read_num++;
            }

            std::stringstream graph_line_stream(graph_line);

            auto g = load_graph(estd::mut(graph_line_stream));

            try { g.remove_edge({start, stop}); } catch (...) {}

            auto cp_res = get_connectivity_pairs(g, start, stop);
            auto mixed_paths_res = get_mixed_paths_count(g, start, stop);

            try {
                estd::throw_assert(cp_res.size() == mixed_paths_res.size(), "Size does not match");
                estd::throw_assert(std::equal(cp_res.begin(), cp_res.end(), mixed_paths_res.begin()),
                    "Contents does not match");
            }
            catch (const std::exception &e)
            {
                if (cp_res.size() == mixed_paths_res.size())
                {
                    for (int i = 0; i < cp_res.size(); i++)
                    {
                        auto lhs = cp_res[i];
                        auto rhs = mixed_paths_res[i];

                        if (lhs.first == rhs.first and lhs.second <= rhs.second)
                            continue;
                        else
                        {
                            std::cerr << std::endl;
                            std::cerr << e.what() << std::endl;
                            std::cerr << "Graph [" << graph_number << "]: " << g << std::endl;
                            std::cerr << "start: " << start << ", stop: " << stop << std::endl;
                            std::cerr << "CP: " << cp_res << std::endl;
                            std::cerr << "MP: " << mixed_paths_res << std::endl;
                            return -1;
                        }
                    }
                }
                else
                    return -1;
            }
        }

        count++;

        if (count % 100 == 0)
            std::cerr << ".";
        if (count % 10000 == 0)
            std::cerr << "\n";
    }
}
