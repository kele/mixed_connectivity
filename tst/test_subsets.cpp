#include "catch.hpp"

#include "subsets.hpp"
#include <iostream>

std::vector<int> seq {1, 2, 3, 4};

TEST_CASE("Empty subset", "[subsets]")
{
    SubsetGenerator<int> generator;
    generator.init(seq, 0);

    REQUIRE(generator.get().empty());
    REQUIRE(generator.next() == false);
}

TEST_CASE("Subsets of size 2", "[subsets]")
{
    SubsetGenerator<int> generator;
    generator.init(seq, 2);

    std::vector<std::vector<int>> expected {
        {1, 2}, {1, 3}, {1, 4},
        {2, 3}, {2, 4},
        {3, 4}
    };

    do {
        auto current = generator.get();

        bool found = false;
        for (int i = 0; i < expected.size(); i++) {
            bool different = false;
            for (int j = 0; j < expected[i].size(); j++) {
                if (expected[i][j] != current[j]) {
                    different = true;
                    break;
                }
            }

            if (different)
                continue;

            found = true;
            expected.erase(expected.begin() + i);
            break;
        }
        if (!found)
            FAIL("Cannot find generater subset");
    } while (generator.next());

    REQUIRE(expected.empty());
}
