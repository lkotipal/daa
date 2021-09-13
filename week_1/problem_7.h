#pragma once
#include <vector>

int findMedian(std::vector<int>::iterator min, std::vector<int>::iterator max);
int findMedian(std::vector<int>& v);
std::vector<int>::iterator partition(std::vector<int>::iterator min, std::vector<int>::iterator max, int p);
int select(std::vector<int>::iterator min, std::vector<int>::iterator max, int j);