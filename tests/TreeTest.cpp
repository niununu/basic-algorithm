#include <catch2/catch_test_macros.hpp>
#include "../include/Tree.h"

TEST_CASE("Traverse", "[TreeTest]")
{
    auto tree = std::make_shared<Tree>();
    std::vector<int> testData = {1, 2, 3, 4, 5, 6, 7}; 
    auto rootNode = tree->createTree(testData);
    SECTION("preOrder")
    {
        tree->preOrderTraverse(rootNode);
        REQUIRE(tree->mResult.size() == testData.size());
        for (int i = 0; i < tree->mResult.size(); ++i)
        {
            tree->mResult[i] == testData[i];
        }
    }
}