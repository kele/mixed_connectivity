#include "graph.hpp"

#include <cstring>

namespace
{
    const char *SEPARATOR = ";";
} // anonymous namespace


SimpleGraph load_graph(const std::string &input_string)
{
    char *s = new char[input_string.size()];
    strcpy(s, input_string.c_str());

    auto token = strtok(s, SEPARATOR);
    token = strtok(NULL, SEPARATOR); // skip the first (empty) part

    int size; sscanf(token, "n%dg", &size);

    SimpleGraph g(size);

    int a = 0;
    while ((token = strtok(NULL, SEPARATOR)))
    {
        int x;
        while (scanf("%d", &x))
            g.add_edge({a, x});
        a++;
    }

    delete [] s;

    return g;
}

