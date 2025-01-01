
#include <cstdint>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

// https://adventofcode.com/2024/day/3

static bool is_valid(const std::vector<std::string>& lines, int32_t x, int32_t y)
{
    if (x < 0 || x >= lines.size()) {
        return false;
    }
    if (y < 0 || y >= lines[x].size()) {
        return false;
    }
    return true;
}

static int32_t get_count_part1(const std::vector<std::string>& lines, const int32_t x, const int32_t y)
{
    constexpr int32_t MAX_WAY = 8;
    const std::string XMAS_STR = "XMAS";
    bool ok[MAX_WAY] = { true, true, true, true, true, true, true, true };
    const int32_t x_way[MAX_WAY] = { +1, +1, 0, -1, -1, -1, 0, +1 };
    const int32_t y_way[MAX_WAY] = { 0, +1, +1, +1, 0, -1, -1, -1 };
    char debug[MAX_WAY][5];
    ::memset(debug, 0, sizeof(debug));

    for (int32_t way = 0; way < MAX_WAY; way++) {
        int32_t xx = 0;
        int32_t yy = 0;
        debug[way][0] = XMAS_STR[0];

        for (int32_t i = 1; i < XMAS_STR.size(); i++) {
            xx = x + x_way[way] * i;
            yy = y + y_way[way] * i;
            if (!is_valid(lines, xx, yy) || lines[xx][yy] != XMAS_STR[i]) {
                ok[way] = false;
            }
            if (is_valid(lines, xx, yy)) {
                debug[way][i] = lines[xx][yy];
            }
        }
    }
    int32_t count = 0;
    for (int32_t way = 0; way < 8; way++) {
        if (ok[way]) {
            count++;
        }
    }
    return count;
}

static int32_t get_count_part2(const std::vector<std::string>& lines, const int32_t x, const int32_t y)
{
    constexpr int32_t MAX_WAY = 5;
    const int32_t x_way[MAX_WAY] = { 0, 1, 1, -1, -1 };
    const int32_t y_way[MAX_WAY] = { 0, 1, -1, -1, 1 };
    const std::vector<std::string> XMAS_STR = {
        "ASSMM",
        "ASMMS",
        "AMMSS",
        "AMSSM",
    };
    std::string str;

    for (int32_t i = 0; i < MAX_WAY; i++) {
        int32_t xx = x + x_way[i];
        int32_t yy = y + y_way[i];
        if (is_valid(lines, xx, yy)) {
            str += lines[xx][yy];
        }
    }
    int32_t count = 0;
    std::for_each(XMAS_STR.begin(), XMAS_STR.end(), [&](const std::string& s) {
        if (s == str) {
            count = 1;
        }
    });

    return count;
}

int32_t aoc_2024_day_4(const std::string filename, const int32_t part)
{
    std::ifstream file(filename);
    int32_t count = 0;
    const char start_char = part == 2 ? 'A' : 'X';
    if (file.is_open()) {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        for (int32_t x = 0; x < lines.size(); x++) {
            for (int32_t y = 0; y < lines[x].size(); y++) {
                if (lines[x][y] == start_char) {
                    if (part == 1) {
                        count += get_count_part1(lines, x, y);
                    } else {
                        count += get_count_part2(lines, x, y);
                    }
                }
            }
        }
    }
    file.close();
    return count;
}