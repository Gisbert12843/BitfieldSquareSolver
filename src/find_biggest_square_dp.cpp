#include "../include/find_biggest_square_dp.h"
#include "algorithm"

int get_biggest_square_dp(std::vector<std::vector<bool>> &tt, std::vector<std::vector<int>> &dp_tt, int x_pos, int y_pos)
{
    // std::cout << " x_pos: " << x_pos << " y_pos: " << y_pos << "\n";
    if (dp_tt[y_pos][x_pos] != -1)
    {
        return dp_tt[y_pos][x_pos];
    }

    if (tt[y_pos][x_pos] == 0)
    {
        // std::cout << "  return 0\n";
        dp_tt[y_pos][x_pos] = 0;
        return 0;
    }
    if (x_pos >= tt[y_pos].size() - 1 || y_pos >= tt.size() - 1)
    {
        // std::cout << "  return 0\n";
        dp_tt[y_pos][x_pos] = 1;
        return 1;
    }
    int right_max = 0;
    int bottom_right_max = 0;
    int bottom_left_max = 0;

    right_max = get_biggest_square_dp(tt, dp_tt, x_pos + 1, y_pos);
    if (right_max > 0)
        bottom_right_max = get_biggest_square_dp(tt, dp_tt, x_pos + 1, y_pos + 1);
    if (bottom_right_max > 0)
        bottom_left_max = get_biggest_square_dp(tt, dp_tt, x_pos, y_pos + 1);

    // std::cout << "  right_max: " << right_max << " bottom_right_max: " << bottom_right_max << " bottom_left_max: " << bottom_left_max << "\n";
    auto min = 1 + std::min({right_max, bottom_right_max, bottom_left_max});
    dp_tt[y_pos][x_pos] = min;
    // std::cout << "  return " << min << "\n";
    return min;
}

bool solve_biggest_square_dp(std::vector<std::vector<bool>> &tt, int &x_pos, int &y_pos, int &square_size)
{
    std::vector<std::vector<int>> dp_tt(tt.size(), std::vector<int>(tt[0].size(), -1));

    for (int y = 0; y < tt.size(); y++)
    {
        for (int x = 0; x < tt[0].size(); x++)
        {
            // std::cout << "x: " << x << " y: " << y << "\n";
            int size = get_biggest_square_dp(tt, dp_tt, x, y);
            if (size > square_size)
            {
                // std::cout << "Found new square with size: " << size << " at position: (" << x << "," << y << ")\n";
                square_size = size;
                x_pos = x;
                y_pos = y;
            }
            // std::cout << "\n";
        }
    }

    return true;
}

bool solve_biggest_square_dp_2_1(std::vector<std::vector<bool>> &tt, int &x_pos, int &y_pos, int &square_size)
{
    int tt_size = tt.size();
    int tt0_size = tt[0].size();

    std::vector<std::vector<int>> dp_tt(tt_size, std::vector<int>(tt0_size, 0));

    for (int y = 0; y < tt_size; y++)
    {
        for (int x = 0; x < tt0_size; x++)
        {
            if (tt[y][x] == 0)
            {
                dp_tt[y][x] = 0;
                continue;
            }
            if (x == 0 || y == 0)
            {
                dp_tt[y][x] = 1;
                continue;
            }
            dp_tt[y][x] = 1 + std::min({dp_tt[y - 1][x], dp_tt[y - 1][x - 1], dp_tt[y][x - 1]});

            if (dp_tt[y][x] > square_size)
            {
                square_size = dp_tt[y][x];
                x_pos = x - square_size + 1;
                y_pos = y - square_size + 1;
            }
        }
    }
    if (square_size > 0)
        return true;
    return false;
}
