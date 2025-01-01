#include "lib/aoc_2024_day_4.h"
#include "gtest/gtest.h"
#include <vector>

TEST(AOC2024Day4, TestInput1Part1)
{
    EXPECT_EQ(aoc_2024_day_4("/Users/loblue/work/aoc/2024/day/4/data/input.txt", 1), 4);
}

TEST(AOC2024Day4, TestInput2Part1)
{
    EXPECT_EQ(aoc_2024_day_4("/Users/loblue/work/aoc/2024/day/4/data/input2.txt", 1), 18);
}

TEST(AOC2024Day4, TestInput3Part1)
{
    EXPECT_EQ(aoc_2024_day_4("/Users/loblue/work/aoc/2024/day/4/data/input3.txt", 1), 2685);
}

TEST(AOC2024Day4, TestPart2Input1)
{
    EXPECT_EQ(aoc_2024_day_4("/Users/loblue/work/aoc/2024/day/4/data/part2input1.txt", 2), 9);
}

TEST(AOC2024Day4, TestInput3Part2)
{
    EXPECT_EQ(aoc_2024_day_4("/Users/loblue/work/aoc/2024/day/4/data/input3.txt", 2), 2048);
}
