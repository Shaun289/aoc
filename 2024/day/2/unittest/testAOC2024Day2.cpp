#include "lib/aoc_2024_day_2.h"
#include "gtest/gtest.h"
#include <vector>

TEST(AOC2024Day2, TestInputPart1)
{
    EXPECT_EQ(aoc_2024_day_2("/Users/loblue/work/aoc/2024/day/2/data/TestInput.txt", 1), 2);
}

TEST(AOC2024Day2, TestInputPart2)
{
    EXPECT_EQ(aoc_2024_day_2("/Users/loblue/work/aoc/2024/day/2/data/TestInput.txt", 2), 4);
}

TEST(AOC2024Day2, TestPuzzle)
{
    EXPECT_EQ(aoc_2024_day_2("/Users/loblue/work/aoc/2024/day/2/data/input.txt", 1), 660);
    EXPECT_EQ(aoc_2024_day_2("/Users/loblue/work/aoc/2024/day/2/data/input.txt", 2), 689);
}
