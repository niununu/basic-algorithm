#include <catch2/catch_test_macros.hpp>
#include "../include/Sort.h"
#include <vector>
#include <algorithm>
#include <memory>

namespace SortTest
{
    class SortTestFixture
    {
    public:
        SortTestFixture()
        {
        }

        void sortTest(SortBasePtr sort)
        {
            auto expectResult = input;
            std::sort(expectResult.begin(), expectResult.end());
            auto output = sort->sortFun(input);
            isSameOrderVector(output, expectResult);
        }
    private:
        std::vector<int> input = {4, 78, 90, 0, 76, 89, 77, 23, 1, 4};
        // 4 78 90 23 76 89 77 0 1 4
        SortBasePtr sort;
    private:
        void isSameOrderVector(std::vector<int> vec1, std::vector<int> vec2)
        {
            REQUIRE(vec1.size() == vec2.size());
            for (auto i = 0; i < vec1.size(); ++i)
            {
                REQUIRE(vec1[i] == vec2[i]);
            }
        }
    };

    TEST_CASE_METHOD(SortTestFixture, "SortTest", "[SortTest]")
    {
        SECTION("Buddle Sort")
        {
            sortTest(std::make_shared<Buddle>());
        }

        SECTION("Heap Sort")
        {
            sortTest(std::make_shared<Heap>());
        }
        // auto output = sort->sortFun(input);
        // isSameOrderVector(output, expectResult);
    }
} // namespace SortTest

