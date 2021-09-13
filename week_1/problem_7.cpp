#include <algorithm>
#include <cmath>
#include <iostream>
#include "problem_7.h"

int findMedian(std::vector<int>::iterator min, std::vector<int>::iterator max) 
{
	return select(min, max, ceil((double) (max - min)/2) - 1);
}

int findMedian(std::vector<int>& v) 
{
	return findMedian(v.begin(), v.end());
}

std::vector<int>::iterator partition(std::vector<int>::iterator min, std::vector<int>::iterator max, int p) 
{ 
	// Lomuto
	auto i = min;
	for (auto j = min; j < max - 1; ++j) {
		// Swap performed here since we need to make sure one of the pivot values is stored in v[max - 1]
		if (*j == p)
			std::iter_swap(j, max-1);
		if (*j <= p) {
			std::iter_swap(i, j);
			++i;
		}
	}
	std::iter_swap(i, max-1);
	return i;
}

int select(std::vector<int>::iterator min, std::vector<int>::iterator max, int j)
{
	int n = max - min;
	if (n <= 5) {
		std::sort(min, max);
		return *(min + j);
	}
	else {
		std::vector<int> m(ceil((double) n/5));
		for (int i = 0; i < floor((double) n/5); ++i)
			m[i] = findMedian(min + i*5, min + (i+1)*5);
		if (n % 5)
			m[floor((double) n/5)] = findMedian(min + 5*floor((double) n/5), max);
		int p = findMedian(m);

		auto x = partition(min, max, p);
		if (j == x - min) {
			return p;
		} else if (x - min > j) {
			return select(min, x, j);
		} else {
			return select(x, max, j - (x - min));
		}
	}
}
