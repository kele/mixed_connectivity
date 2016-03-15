#include "print_dot.hpp"

const char *IDENT = "    ";
const char *EDGE = "--";
const char *MARK = "[shape=box]";

void print_dot(estd::mutref<std::ostream> os, const std::string &graphname,
        const SimpleGraph &g, const std::vector<int> &marked)
{
    std::ostream &oss = os;

    oss << "graph " << graphname << "{\n";

    for (auto v : marked)
        oss << IDENT << v << " " << MARK << ";\n";

    for (const auto &e : g.edges())
        oss << IDENT << e.start << " " << EDGE << " " << e.stop << ";\n";
    oss << "}\n";
}
