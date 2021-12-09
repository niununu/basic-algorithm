#include <catch2/catch_test_macros.hpp>
#include "../include/Search.h"

TEST_CASE("BFS::Search", "[SearchTest]")
{
    auto bfs = std::make_shared<BFS>();
    bfs->bfsFun();
    REQUIRE(true);
}