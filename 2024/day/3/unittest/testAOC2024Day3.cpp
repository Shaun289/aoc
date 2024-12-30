#include "lib/aoc_2024_day_3.h"
#include "gtest/gtest.h"
#include <vector>

TEST(AOC2024Day3, TestInputPart1)
{
    EXPECT_EQ(aoc_2024_day_3("/Users/loblue/work/aoc/2024/day/3/data/Input.txt", 1), 161);
}

TEST(AOC2024Day3, TestPuzzlePart1)
{
    EXPECT_EQ(aoc_2024_day_3("/Users/loblue/work/aoc/2024/day/3/data/puzzleInput.txt", 1), 155955228);
}

TEST(AOC2024Day3, TestInputPart2)
{
    EXPECT_EQ(aoc_2024_day_3("/Users/loblue/work/aoc/2024/day/3/data/part2Input.txt", 2), 48);
}

TEST(AOC2024Day3, TestPuzzlePart2)
{
    EXPECT_EQ(aoc_2024_day_3("/Users/loblue/work/aoc/2024/day/3/data/puzzleInput.txt", 2), 100189366);
}
