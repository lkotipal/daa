#include <algorithm>
#include <climits>
#include "problem_6.h"

std::array<std::vector<int>::const_iterator, 2> maximumDifference(std::vector<int>::const_iterator min, std::vector<int>::const_iterator max) 
{
	auto pivot = min + (max-min) / 2;
	auto i_prime = std::min_element(min, pivot);
	auto j_prime = std::max_element(pivot, max);
	std::array<std::vector<int>::const_iterator, 2> ij = {i_prime, j_prime};
	if (pivot > min && pivot < max) {
		auto left_ij = maximumDifference(min, pivot);
		if (*left_ij[1] - *left_ij[0] > *ij[1] - *ij[0])
			ij = left_ij;

		auto right_ij = maximumDifference(pivot, max);
		if (*right_ij[1] - *right_ij[0] > *ij[1] - *ij[0])
			ij = right_ij;
	}
	return ij;
}

std::array<long, 2> maximumDifference(std::vector<int>& v) 
{
	auto ij = maximumDifference(v.begin(), v.end());
	return {ij[0] - v.begin(), ij[1] - v.begin()};
}

int checkMaximumDifference(std::vector<int>& v) 
{
	int d = INT_MIN;
	int min = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] - min > d)
			d = v[i] - min;
		if (v[i] < min)
			min = v[i];
	}
	return d;
}
