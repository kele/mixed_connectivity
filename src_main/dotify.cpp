#include <iostream>
#include <fstream>

#include "print_dot.hpp"
#include "load_graph.hpp"

const int ARGS_NUM = 4;

void print_usage()
{
    std::cout << "dotify [infile] [graphs_file] [outout_prefix]" << std::endl;
    std::cout << "WARNING! It is assumed that [infile] is sorted." << std::endl;
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
    const auto output_prefix = std::string(argv[3]);

    std::ifstream input(input_filename);
    std::ifstream graphs_input(graphs_filename);
    std::string line;
    std::string graph_line;

    int graph_read_num = 0;
    int count = 0;
    while (input.good())
    {
        std::getline(input, line);

        if (line != "")
        {
            int graph_number, start, stop;
            std::stringstream line_stream(line);
            line_stream >> graph_number >> start >> stop;

            while (graph_read_num < graph_number)
            {
                std::getline(graphs_input, graph_line);
                graph_read_num++;
            }

            std::stringstream graph_line_stream(graph_line);
            auto g = load_graph(estd::mut(graph_line_stream));

            std::stringstream out_filename;
            out_filename << output_prefix << graph_number << "__" << start << "_" << stop;

            std::ofstream output(out_filename.str());
            print_dot(estd::mut(output), out_filename.str(), g, {start, stop});
        }

        count++;

        if (count % 100 == 0)
            std::cerr << ".";
    }
}
