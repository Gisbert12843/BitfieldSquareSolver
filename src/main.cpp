#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include <algorithm>
#include <cstdint>
#include <thread>
#include "include/benchmark.h"
#include "include/find_biggest_square.h"
#include "include/find_biggest_square_dp.h"

#define TABLE_SIZE_X 10000
#define TABLE_SIZE_Y 40000

void print_truth_table(std::vector<std::vector<bool>> &tt)
{
    std::cout << "\n";
    std::cout << "\n";

    for (auto y : tt)
    {

        for (auto x : y)
            std::cout << x << " ";
        std::cout << "\n";
    }
    std::cout << "\n";
}

void print_truth_table_marking_square(std::vector<std::vector<bool>> &tt, int square_size, int start_pos_x, int start_pos_y, bool print_table = true)
{
    std::cout << "\n";
    std::cout << "\n";
    if (print_table)
        for (int y = 0; y < tt.size(); y++)
        {
            for (int x = 0; x < tt[y].size(); x++)
            {
                if (y >= start_pos_y && y <= start_pos_y + square_size - 1 && x >= start_pos_x && x <= start_pos_x + square_size - 1)
                    std::cout << "x" << " ";
                else
                    std::cout << tt[y][x] << " ";
            }
            std::cout << "\n";
        }
    std::cout << "Found square with size: " << square_size << " at position: (" << start_pos_x << "," << start_pos_y << ")\n";
    std::cout << "\n";
}

int main()
{
    std::vector<std::vector<bool>> farm_area_truth_table(TABLE_SIZE_Y, std::vector<bool>(TABLE_SIZE_X, false));

    std::random_device rd;        // Seed
    std::mt19937 generator(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<uint8_t> distribution(0, 1);
    {
        Benchmark b1("Filling");
        for (auto &y : farm_area_truth_table)
        {
            for (auto it = y.begin(); it != y.end(); it++)
            {
                *it = distribution(generator);
            }
        }
    }
    // print_truth_table(farm_area_truth_table);

    int x_pos = 0, y_pos = 0, square_size = 0;

#if 1
    bool result;
    {
        Benchmark b1("solve_biggest_square_dp");
        result = solve_biggest_square_dp_2_1(farm_area_truth_table, x_pos, y_pos, square_size);
    }
    if (result)
        print_truth_table_marking_square(farm_area_truth_table, square_size, x_pos, y_pos, false);
#else
    Result result;
    {
        Benchmark b1("solve_biggest_square_dp2");
        result = solve_biggest_square_dp2(farm_area_truth_table);
    }
    x_pos = result.top_left_row;
    y_pos = result.top_left_col;
    square_size = result.size;
    if (square_size > 0)
        print_truth_table_marking_square(farm_area_truth_table, square_size, x_pos, y_pos, false);

#endif
    else
        std::cout << "No square found\n";
}