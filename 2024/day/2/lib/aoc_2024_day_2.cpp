#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// https://adventofcode.com/2024/day/2
uint32_t aoc_2024_day_2(const std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    uint32_t count = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int32_t prev = 0;
        int32_t next = 0;
        iss >> prev >> next;
        const bool increasing = prev <= next;
        bool safe = true;
        if (prev == next) {
            safe = false;
        }

        do {
            if (increasing != (prev <= next)) {
                safe = false;
                break;
            }
            int32_t abs = std::abs(prev - next);
            if (abs == 0 || abs > 3) {
                safe = false;
                break;
            }
            prev = next;
        } while (iss >> next);

        if (safe) {
            std::cout << line << std::endl;
            count++;
        }
    }
    file.close();
    return count;
}
