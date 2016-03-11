#include "catch.hpp"

#include <sstream>
#include <functional>
#include <set>

#include "graph.hpp"
#include "path.hpp"


TEST_CASE("Natural ordering for a graph of size 4.", "[all_paths]")
{
    std::set<std::string> generated_paths;

    SimpleGraph g(4);

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            g.add_edge({i, j});

    auto prettify_path = [&generated_paths](const std::vector<int> &path, const SimpleGraph&)
    {
        std::stringstream ss;
        for (const auto &v : path)
            ss << v;
        generated_paths.insert(ss.str());
    };

    /* 1 -> 2 -> 3 -> 4 */
    /* 1 -> 2 -> 4 */
    /* 1 -> 3 - > 4 */
    /* 1 -> 4 */

    for_all_paths(g, 0, 3, prettify_path);

    REQUIRE(generated_paths.size() == 4);
    REQUIRE(generated_paths.count("0123"));
    REQUIRE(generated_paths.count("013"));
    REQUIRE(generated_paths.count("023"));
    REQUIRE(generated_paths.count("03"));
}
