#include <algorithm>
#include <cstdint>
#include <vector>

// https://adventofcode.com/2024/day/1

int32_t historianHisteria(std::vector<int32_t> left, std::vector<int32_t> right)
{
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int32_t sum = 0;

    for (size_t i = 0; i < left.size(); i++) {
        sum += std::abs(left[i] - right[i]);
    }

    return sum;
}