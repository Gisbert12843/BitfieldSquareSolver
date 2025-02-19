#include "../include/find_biggest_square.h"
#include "algorithm"


inline int get_biggest_square(std::vector<std::vector<bool>> &tt, int x_pos, int y_pos)
{
    // std::cout << " x_pos: " << x_pos << " y_pos: " << y_pos << "\n";
    if (tt[y_pos][x_pos] == 0)
    {
        // std::cout << "  return 0\n";
        return 0;
    }
    if (x_pos >= tt[y_pos].size() - 1 || y_pos >= tt.size() - 1)
    {
        // std::cout << "  return 0\n";
        return 1;
    }
    int right_max = 0;
    int bottom_right_max = 0;
    int bottom_left_max = 0;

    right_max = get_biggest_square(tt, x_pos + 1, y_pos);
    if (right_max > 0)
        bottom_right_max = get_biggest_square(tt, x_pos + 1, y_pos + 1);
    if (bottom_right_max > 0)
        bottom_left_max = get_biggest_square(tt, x_pos, y_pos + 1);

    // std::cout << "  right_max: " << right_max << " bottom_right_max: " << bottom_right_max << " bottom_left_max: " << bottom_left_max << "\n";
    auto min = 1 + std::min({right_max, bottom_right_max, bottom_left_max});
    // std::cout << "  return " << min << "\n";
    return min;
}

bool solve_biggest_square(std::vector<std::vector<bool>> &tt, int &x_pos, int &y_pos, int &square_size)
{
    for (int y = 0; y < tt.size(); y++)
    {
        for (int x = 0; x < tt.size(); x++)
        {
            // std::cout << "x: " << x << " y: " << y << "\n";
            int size = get_biggest_square(tt, x, y);
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
    if(square_size == 0)
        return false;

    return true;
}
