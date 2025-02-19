#include "catch.hpp"
#include "catch2/generators/catch_generators_all.hpp"

#include <vector>
#include <tuple>
#include <algorithm>
#include <cstdint>
#include <thread>
#include "../include/find_biggest_square.h"
#include "../include/find_biggest_square_dp.h"
#include "../include/benchmark.h"

TEST_CASE("find_biggest_square", "")
{
    int TABLE_SIZE_X = GENERATE(100, 1000);
    int AREA_SIZE = 10;

    const int TABLE_SIZE_Y = TABLE_SIZE_X;

    std::vector<std::vector<bool>> farm_area_truth_table(TABLE_SIZE_Y, std::vector<bool>(TABLE_SIZE_X, false));
    REQUIRE(farm_area_truth_table.size() == TABLE_SIZE_Y);
    REQUIRE(farm_area_truth_table[0].size() == TABLE_SIZE_X);

    int x_pos = 0, y_pos = 0, square_size = 0;

    for (int i = TABLE_SIZE_X * 0.1; i < TABLE_SIZE_X * 0.1 + AREA_SIZE; i++)
    {
        for (int j = TABLE_SIZE_X * 0.1; j < TABLE_SIZE_X * 0.1 + AREA_SIZE; j++)
        {
            farm_area_truth_table[i][j] = 1;
        }
    }

    Benchmark b1("find_biggest_square with Table size:          " + std::to_string(TABLE_SIZE_X) + " Area size: " + std::to_string(AREA_SIZE));

    if (solve_biggest_square(farm_area_truth_table, x_pos, y_pos, square_size))
    {
        CHECK(y_pos == static_cast<int>(TABLE_SIZE_Y * 0.1));
        CHECK(x_pos == static_cast<int>(TABLE_SIZE_X * 0.1));
        CHECK(square_size == static_cast<int>(AREA_SIZE));
    }
}

TEST_CASE("find_biggest_square_dp", "")
{

    int TABLE_SIZE_X = GENERATE(100, 1000);
    int AREA_SIZE = GENERATE_COPY(TABLE_SIZE_X * 0.1, TABLE_SIZE_X * 0.2);

    const int TABLE_SIZE_Y = TABLE_SIZE_X;

    std::vector<std::vector<bool>> farm_area_truth_table(TABLE_SIZE_Y, std::vector<bool>(TABLE_SIZE_X, false));
    REQUIRE(farm_area_truth_table.size() == TABLE_SIZE_Y);
    REQUIRE(farm_area_truth_table[0].size() == TABLE_SIZE_X);

    int x_pos = 0, y_pos = 0, square_size = 0;

    for (int i = TABLE_SIZE_X * 0.1; i < TABLE_SIZE_X * 0.1 + AREA_SIZE; i++)
    {
        for (int j = TABLE_SIZE_X * 0.1; j < TABLE_SIZE_X * 0.1 + AREA_SIZE; j++)
        {
            farm_area_truth_table[i][j] = 1;
        }
    }
    Benchmark b1("find_biggest_square_db with Table size:      " + std::to_string(TABLE_SIZE_X) + " Area size: " + std::to_string(AREA_SIZE));
    CHECK(solve_biggest_square_dp(farm_area_truth_table, x_pos, y_pos, square_size));
    CHECK(y_pos == static_cast<int>(TABLE_SIZE_Y * 0.1));
    CHECK(x_pos == static_cast<int>(TABLE_SIZE_X * 0.1));
    CHECK(AREA_SIZE == static_cast<int>(AREA_SIZE));
}

TEST_CASE("solve_biggest_square_dp_2_1", "")
{

    int TABLE_SIZE_X = GENERATE(100, 1000);
    int AREA_SIZE = GENERATE_COPY(TABLE_SIZE_X * 0.1, TABLE_SIZE_X * 0.2);

    const int TABLE_SIZE_Y = TABLE_SIZE_X;

    std::vector<std::vector<bool>> farm_area_truth_table(TABLE_SIZE_Y, std::vector<bool>(TABLE_SIZE_X, false));
    REQUIRE(farm_area_truth_table.size() == TABLE_SIZE_Y);
    REQUIRE(farm_area_truth_table[0].size() == TABLE_SIZE_X);

    int x_pos = 0, y_pos = 0, square_size = 0;

    for (int i = TABLE_SIZE_X * 0.1; i < TABLE_SIZE_X * 0.1 + AREA_SIZE; i++)
    {
        for (int j = TABLE_SIZE_X * 0.1; j < TABLE_SIZE_X * 0.1 + AREA_SIZE; j++)
        {
            farm_area_truth_table[i][j] = 1;
        }
    }
    Benchmark b1("find_biggest_square_db   with Table size: " + std::to_string(TABLE_SIZE_X) + " Area size: " + std::to_string(AREA_SIZE));
    CHECK(solve_biggest_square_dp_2_1(farm_area_truth_table, x_pos, y_pos, square_size));
    CHECK(y_pos == static_cast<int>(TABLE_SIZE_Y * 0.1));
    CHECK(x_pos == static_cast<int>(TABLE_SIZE_X * 0.1));
    CHECK(AREA_SIZE == static_cast<int>(AREA_SIZE));
}
