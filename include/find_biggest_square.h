#pragma once
#include <vector>
#include <cstdint>

inline int get_biggest_square(std::vector<std::vector<bool>> &tt, int x_pos, int y_pos);

bool solve_biggest_square(std::vector<std::vector<bool>> &tt, int &x_pos, int &y_pos, int &square_size);