#pragma once
#include <vector>
#include <cstdint>

int get_biggest_square_dp(std::vector<std::vector<bool>> &tt, std::vector<std::vector<int>> &dp_tt, int x_pos, int y_pos);

bool solve_biggest_square_dp(std::vector<std::vector<bool>> &tt, int &x_pos, int &y_pos, int &square_size);
bool solve_biggest_square_dp_2_1(std::vector<std::vector<bool>> &tt, int &x_pos, int &y_pos, int &square_size);