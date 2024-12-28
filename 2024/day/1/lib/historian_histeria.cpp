#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// https://adventofcode.com/2024/day/1
bool getInput(const std::string filename, std::vector<int32_t>* left, std::vector<int32_t>* right)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int32_t l, r;
        if (!(iss >> l >> r)) {
            return false;
        }
        left->push_back(l);
        right->push_back(r);
    }
    file.close();
    return true;
}

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