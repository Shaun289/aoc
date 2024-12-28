#include "lib/historian_histeria.h"
#include "gtest/gtest.h"
#include <vector>

TEST(HistorianHisteria, Test1)
{
    std::vector<int32_t> left = { 1, 2, 3, 4, 5 };
    std::vector<int32_t> right = { 1, 2, 3, 4, 5 };

    EXPECT_EQ(historianHisteria(left, right), 0);
}

TEST(HistorianHisteria, Test2)
{
    std::vector<int32_t> left = { 3, 4, 2, 1, 3, 3 };
    std::vector<int32_t> right = { 4, 3, 5, 3, 9, 3 };

    EXPECT_EQ(historianHisteria(left, right), 11);
}

TEST(HistorianHisteria, TestPuzzle)
{
    std::vector<int32_t> left;
    std::vector<int32_t> right;

    EXPECT_TRUE(getInput("/Users/loblue/work/aoc/2024/day/1/input.txt", &left, &right));
    EXPECT_EQ(historianHisteria(left, right), 765748);
}
