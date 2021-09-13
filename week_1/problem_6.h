#pragma once
#include <array>
#include <vector>

std::array<std::vector<int>::const_iterator, 2> maximumDifference(std::vector<int>::const_iterator min, std::vector<int>::const_iterator max);
std::array<long long, 2> maximumDifference(std::vector<int>& v);
int checkMaximumDifference(std::vector<int>& v);