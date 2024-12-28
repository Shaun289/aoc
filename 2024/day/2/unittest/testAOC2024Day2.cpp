#include "lib/aoc_2024_day_2.h"
#include "gtest/gtest.h"
#include <vector>

TEST(AOC2024Day2, TestInput)
{
    EXPECT_EQ(aoc_2024_day_2("/Users/loblue/work/aoc/2024/day/2/data/TestInput.txt"), 2);
    EXPECT_EQ(aoc_2024_day_2("/Users/loblue/work/aoc/2024/day/2/data/input.txt"), 660);
}
