#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

static bool isOk(const int32_t prev, const int32_t next, const bool increasing)
{
    const int32_t abs = std::abs(prev - next);
    return increasing == (prev <= next) && abs > 0 && abs <= 3;
}

static bool checkSafe(const std::vector<int32_t>& vec)
{
    const bool increasing = vec[0] <= vec[1];
    for (auto i = 0; i < vec.size() - 1; i++) {
        int32_t prev = i;
        int32_t next = i + 1;
        if (next == i) {
            next = i + 2;
            if (next >= vec.size()) {
                return false;
            }
        }
        if (!isOk(vec[prev], vec[next], increasing)) {
            return false;
        }
    }
    return true;
}

// https://adventofcode.com/2024/day/2
// prev와 next 어떤걸 빼면 되는지 판단해야함
uint32_t aoc_2024_day_2(const std::string filename, int32_t part)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    uint32_t count = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int32_t> vec;

        std::copy(std::istream_iterator<int32_t>(iss), std::istream_iterator<int32_t>(), std::back_inserter(vec));

        bool tolerance = part == 2;
        if (checkSafe(vec)) {
            count++;
        } else {
            if (tolerance) {
                for (auto i = 0; i < vec.size(); i++) {
                    std::vector<int32_t> vec2 = vec;
                    vec2.erase(vec2.begin() + i);
                    if (checkSafe(vec2)) {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    file.close();
    return count;
}
