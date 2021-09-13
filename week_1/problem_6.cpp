#include <algorithm>
#include "problem_6.h"

std::array<int, 2> maximumDifference(std::vector<int>& v, int min, int max) {
	int pivot = min + (max-min) / 2;
	int i_prime = std::min_element(v.begin() + min, v.begin() + pivot) - v.begin();
	int j_prime = std::max_element(v.begin() + pivot, v.begin() + max) - v.begin();
	std::array<int, 2> ij = {i_prime, j_prime};
	if (pivot > min && pivot < max) {
		std::array<int, 2> left_ij = maximumDifference(v, min, pivot);
		if (v[left_ij[1]] - v[left_ij[0]] > v[ij[1]] - v[ij[0]])
			ij = left_ij;

		std::array<int, 2> right_ij = maximumDifference(v, pivot, max);
		if (v[right_ij[1]] - v[right_ij[0]] > v[ij[1]] - v[ij[0]])
			ij = right_ij;
	}
	return ij;
}

std::array<int, 2> maximumDifference(std::vector<int>& v) {
	return maximumDifference(v, 0, v.size());
}

int checkMaximumDifference(std::vector<int>& v) {
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
