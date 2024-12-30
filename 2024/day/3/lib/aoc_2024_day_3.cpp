
#include <cstdint>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

// https://adventofcode.com/2024/day/3

int32_t aoc_2024_day_3(const std::string filename, const int32_t part)
{
    std::ifstream file(filename);
    int32_t sum = 0;
    if (file.is_open()) {
        std::string str;
        file.seekg(0, std::ios::end);
        auto size = file.tellg();
        str.resize(size);
        file.seekg(0, std::ios::beg);
        file.read(&str[0], size);
        bool do_mul = true;
        std::regex re(R"(do\(\)|don't\(\)|mul\((\d+),(\d+)\))");
        std::smatch match;
        while (std::regex_search(str, match, re)) {
            if (match[0].str() == "do()") {
                if (part == 2) {
                    do_mul = true;
                }
            } else if (match[0].str() == "don't()") {
                if (part == 2) {
                    do_mul = false;
                }
            } else {
                if (do_mul) {
                    const int32_t left = std::stoi(match[1].str());
                    const int32_t right = std::stoi(match[2].str());
                    sum += left * right;
                }
            }
            str = match.suffix();
        }
    }
    file.close();
    return sum;
}