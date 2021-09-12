#pragma once
#include <vector>

int findMedian(std::vector<int>& v, int min, int max);
int findMedian(std::vector<int>& v);
int partition(std::vector<int>& v, int p, int min, int max);
int select(std::vector<int>& v, int j, int min, int max);