#include <catch2/catch_test_macros.hpp>
#include "../include/Sort.h"
#include <vector>
#include <algorithm>
#include <memory>

void isSameOrderVector(std::vector<int> vec1, std::vector<int> vec2)
{
    REQUIRE(vec1.size() == vec2.size());
    for (auto i = 0; i < vec1.size(); ++i)
    {
        REQUIRE(vec1[i] == vec2[i]);
    }
}

TEST_CASE("SortTest", "[SortTest]")
{
    std::vector<int> input = {4, 78, 90, 0, 76, 89, 77, 23, 1, 4};
    auto expectResult = input;
    std::sort(expectResult.begin(), expectResult.end());

    SECTION("BuddleSort")
    {
        auto buddleSort = std::make_shared<Buddle>();
        auto output = buddleSort->sortFun(input);
        isSameOrderVector(output, expectResult);
    }
}