#include "catch.hpp"

#include <string>
#include <sstream>

#include "load_graph.hpp"


/* Format: [graph size] -1 ([neighbours] -2)... -3 */

const char *test_example = R"(
5 -1 4 -2 4 -2 4 -2 4 -3
5 -1 3 4 -2 4 -2 4 -3
5 -1 3 4 -2 4 -2 4 -2 4 -3
5 -1 3 4 -2 3 -2 4 -2 4 -3
5 -1 3 4 -2 3 4 -2 4 -3
5 -1 3 4 -2 3 4 -2 4 -2 4 -3
5 -1 3 4 -2 3 4 -2 3 4 -3
5 -1 3 4 -2 3 4 -2 3 4 -2 4 -3
5 -1 2 4 -2 3 4 -3
5 -1 2 4 -2 3 4 -2 4 -3
5 -1 2 4 -2 3 4 -2 4 -2 4 -3
5 -1 2 3 4 -2 4 -2 3 4 -3
5 -1 2 3 4 -2 4 -2 3 4 -2 4 -3
5 -1 2 3 -2 3 4 -2 4 -3
5 -1 2 3 4 -2 3 4 -2 4 -3
5 -1 2 3 4 -2 3 4 -2 4 -2 4 -3
5 -1 2 3 4 -2 3 4 -2 3 4 -2 4 -3
5 -1 2 3 4 -2 2 3 4 -2 4 -3
5 -1 2 3 4 -2 2 3 4 -2 4 -2 4 -3
5 -1 2 3 4 -2 2 3 4 -2 3 4 -2 4 -3
5 -1 1 2 3 4 -2 2 3 4 -2 3 4 -2 4 -3
)";

TEST_CASE("Load graph", "[load_graph]")
{
    std::vector<SimpleGraph> graphs;

    std::stringstream input((std::string(test_example)));
    std::vector<std::string> lines;
    std::string line;

    while (!input.eof())
    {
        std::getline(input, line);
        if (line != "")
        {
            lines.push_back(line);
            graphs.push_back(load_graph(std::stringstream(line)));
        }
    }

    for (int gi = 0; gi < graphs.size(); gi++)
    {
        const auto &g = graphs[gi];

        std::stringstream graph_line_stream;
        graph_line_stream << g.size() << " -1";

        int edges_printed = 0;
        for (int i = 0; i < g.size(); i++)
        {
            const auto &neighbours = g.neighbours(i);
            for (const auto &u : neighbours)
            {
                graph_line_stream << " " << u.stop;
                edges_printed++;
            }

            if (edges_printed != g.num_of_edges())
            {
                if (!neighbours.empty())
                    graph_line_stream << " -2";
            }
            else
            {
                graph_line_stream << " -3";
                break;
            }
        }

        REQUIRE(lines[gi] == graph_line_stream.str());
    }
}
